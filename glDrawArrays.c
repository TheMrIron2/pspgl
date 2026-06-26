#include "pspgl_internal.h"
#include "pspgl_profile_internal.h"


void glDrawArrays (GLenum mode, GLint first, GLsizei count)
{
	PSPGL_PROFILE_INC(draw_arrays_calls);
	__pspgl_varray_draw(mode, first, count);
}
