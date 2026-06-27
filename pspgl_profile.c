#include <string.h>

#include "pspgl_profile_internal.h"
#include "pspgl_dlist.h"

#if PSPGL_PROFILE
struct pspgl_profile_stats __pspgl_profile_stats;
#endif

void pspgl_profile_reset(void)
{
#if PSPGL_PROFILE
	unsigned current = __pspgl_dlist_outstanding_current();

	memset(&__pspgl_profile_stats, 0, sizeof(__pspgl_profile_stats));

	__pspgl_profile_stats.command_list_outstanding_current =
		(unsigned long long)current;
	__pspgl_profile_stats.command_list_outstanding_high_water =
		(unsigned long long)current;
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
	out->command_list_outstanding_current =
		(unsigned long long)__pspgl_dlist_outstanding_current();
	if (out->command_list_outstanding_high_water <
	    out->command_list_outstanding_current)
		out->command_list_outstanding_high_water =
			out->command_list_outstanding_current;
#else
	memset(out, 0, sizeof(*out));
#endif
}
