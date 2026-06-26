#include <string.h>
#include "pspgl_internal.h"
#include "pspgl_texobj.h"
#include "pspgl_profile_internal.h"

void glBindTexture(GLenum target, GLuint id)
{
	struct pspgl_texobj *tobj, *bound;
	struct hashtable *hash = &pspgl_curctx->shared->texture_objects;
	unsigned i;
	GLenum error;

	PSPGL_PROFILE_INC(texture_bind_calls);
	bound = pspgl_curctx->texture.bound;
	tobj = __pspgl_hash_lookup(hash, id);

	if (likely(tobj != NULL)) {
		error = GL_INVALID_OPERATION;

		if (unlikely(tobj->target == 0))
			tobj->target = target;
		else if (unlikely(tobj->target != target))
			goto out_error;
	} else {
		/* if this is a new id, create the texture */
		tobj = __pspgl_texobj_new(id, target);
		psp_log("id %u unknown; creating new texture %p\n", id, tobj);

		error = GL_OUT_OF_MEMORY;
		if (unlikely(tobj == NULL))
			goto out_error;

		__pspgl_hash_insert(hash, id, tobj);
		PSPGL_PROFILE_INC(texture_objects_created);
	}

	if (bound == tobj) {
		PSPGL_PROFILE_INC(texture_bind_redundant);
		return;
	}

	PSPGL_PROFILE_INC(texture_bind_changes);
	if (bound != NULL) {
		int i;

		psp_log("unbinding previous texture %p\n", bound);

		/* save per-texture state in texture object */
		for(i = TEXSTATE_START; i <= TEXSTATE_END; i++)
			bound->ge_texreg[i - TEXSTATE_START] = getReg(i);

		__pspgl_texobj_free(bound);
	}

	psp_log("binding to %u (%p)\n", id, tobj);

	tobj->refcount++;
	pspgl_curctx->texture.bound = tobj;

	/* restore texture state */
	psp_log("updating register state\n");
	for(i = TEXSTATE_START; i <= TEXSTATE_END; i++)
		if (i != CMD_CLUT_LOAD)
			sendCommandi(i, tobj->ge_texreg[i - TEXSTATE_START]);

	if (__pspgl_texobj_cmap(tobj) != NULL)
		pspgl_curctx->hw.dirty |= HWD_CLUT;

	__pspgl_update_texenv(tobj);
#if PSPGL_DIRTY_TEXTURE_FLUSH
	PSPGL_PROFILE_INC(texture_bind_flushes_suppressed);
#else
	sendCommandi(CMD_TEXCACHE_FLUSH, getReg(CMD_TEXCACHE_FLUSH)+1);
#endif
	return;

  out_error:
	GLERROR(error);
}
