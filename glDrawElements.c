#include "pspgl_internal.h"
#include "pspgl_profile_internal.h"


void glDrawElements (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
{
	PSPGL_PROFILE_INC(draw_elements_calls);
	__pspgl_varray_draw_elts(mode, type, indices, count);
}
