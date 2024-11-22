#ifndef HEADER_CARES_STRDUP_H
#define HEADER_CARES_STRDUP_H


/* Copyright 1998 by the Massachusetts Institute of Technology.
 *
 * Permission to use, copy, modify, and distribute this
 * software and its documentation for any purpose and without
 * fee is hereby granted, provided that the above copyright
 * notice appear in all copies and that both that copyright
 * notice and this permission notice appear in supporting
 * documentation, and that the name of M.I.T. not be used in
 * advertising or publicity pertaining to distribution of the
 * software without specific, written prior permission.
 * M.I.T. makes no representations about the suitability of
 * this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 */

#include "ares_setup.h"

extern char *ares_strdup(const char *s1);

#endif /* HEADER_CARES_STRDUP_H */

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
#ifdef __ASM__
__SRCVERSION "$URL: http://f27svn.qnx.com/svn/repos/osr/branches/8.0.0/trunk/cares/dist/src/lib/ares_strdup.h $ $Rev: 2429 $"
#else
__SRCVERSION("$URL: http://f27svn.qnx.com/svn/repos/osr/branches/8.0.0/trunk/cares/dist/src/lib/ares_strdup.h $ $Rev: 2429 $")
#endif
#endif
