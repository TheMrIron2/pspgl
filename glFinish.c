#include "pspgl_internal.h"
#include "pspgl_dlist.h"
#include "pspgl_profile_internal.h"

void glFinish (void)
{
	PSPGL_PROFILE_INC(finishes);
	__pspgl_dlist_submit();
	__pspgl_dlist_await_completion(NULL, NULL);
}
