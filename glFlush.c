#include "pspgl_internal.h"
#include "pspgl_dlist.h"
#include "pspgl_profile_internal.h"

void glFlush (void)
{
	PSPGL_PROFILE_INC(explicit_flushes);
	__pspgl_dlist_submit();
}
