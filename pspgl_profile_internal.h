#ifndef PSPGL_PROFILE_INTERNAL_H
#define PSPGL_PROFILE_INTERNAL_H

#include "pspgl_profile.h"

#ifndef PSPGL_PROFILE
#define PSPGL_PROFILE 0
#endif

#if PSPGL_PROFILE
extern struct pspgl_profile_stats __pspgl_profile_stats;
#define PSPGL_PROFILE_INC(field) \
	(++__pspgl_profile_stats.field)
#define PSPGL_PROFILE_ADD(field, value) \
	(__pspgl_profile_stats.field += (unsigned long long)(value))
#define PSPGL_PROFILE_SET(field, value) \
	(__pspgl_profile_stats.field = (unsigned long long)(value))
#define PSPGL_PROFILE_MAX(field, value) do { \
	unsigned long long __pspgl_profile_value = (unsigned long long)(value); \
	if (__pspgl_profile_stats.field < __pspgl_profile_value) \
		__pspgl_profile_stats.field = __pspgl_profile_value; \
} while (0)
#else
#define PSPGL_PROFILE_INC(field) ((void)0)
#define PSPGL_PROFILE_ADD(field, value) ((void)0)
#define PSPGL_PROFILE_SET(field, value) ((void)0)
#define PSPGL_PROFILE_MAX(field, value) ((void)0)
#endif

#endif
