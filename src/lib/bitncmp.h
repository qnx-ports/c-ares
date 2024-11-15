#ifndef __ARES_BITNCMP_H
#define __ARES_BITNCMP_H


/* Copyright (C) 2005, 2013 by Dominick Meglio
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

#ifndef HAVE_BITNCMP
int ares__bitncmp(const void *l, const void *r, int n);
#else
#define ares__bitncmp(x,y,z) bitncmp(x,y,z)
#endif

#endif /* __ARES_BITNCMP_H */

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
#ifdef __ASM__
__SRCVERSION "$URL: http://f27svn.qnx.com/svn/repos/osr/trunk/cares/dist/src/lib/bitncmp.h $ $Rev: 2429 $"
#else
__SRCVERSION("$URL: http://f27svn.qnx.com/svn/repos/osr/trunk/cares/dist/src/lib/bitncmp.h $ $Rev: 2429 $")
#endif
#endif
