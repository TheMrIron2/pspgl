#include <string.h>

#include "pspgl_profile_internal.h"
#include "pspgl_dlist.h"

#if PSPGL_PROFILE
struct pspgl_profile_stats __pspgl_profile_stats;
#endif

void pspgl_profile_reset(void)
{
#if PSPGL_PROFILE
	memset(&__pspgl_profile_stats, 0, sizeof(__pspgl_profile_stats));
#endif
}

void pspgl_profile_snapshot(struct pspgl_profile_stats *out)
{
	if (out == 0)
		return;

#if PSPGL_PROFILE
	*out = __pspgl_profile_stats;
	out->command_list_capacity_words =
		(unsigned long long)__pspgl_dlist_capacity_words();
#else
	memset(out, 0, sizeof(*out));
#endif
}
