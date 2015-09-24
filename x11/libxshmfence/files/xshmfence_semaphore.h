/*
 * Copyright © 2015 Tobias Nygren
 * Copyright © 2013 Keith Packard
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that copyright
 * notice and this permission notice appear in supporting documentation, and
 * that the name of the copyright holders not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no representations
 * about the suitability of this software for any purpose.  It is provided "as
 * is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */

#ifndef _XSHMFENCE_SEMAPHORE_H_
#define _XSHMFENCE_SEMAPHORE_H_

#include <semaphore.h>

#define LOCK_ALIGN __attribute__((aligned(128)))
#ifndef LIBXSHM_PAGESIZE
#error unknown machine page size
#endif
#define PAGE_ALIGN __attribute__((aligned(LIBXSHM_PAGESIZE)))

/*
 * the fence is divided into two memory pages:
 * page 1 contains process shared state
 * page 2 contains process local state
 */

struct xshmfence {
	/* page 1 */
	int refcnt LOCK_ALIGN;
	int triggered LOCK_ALIGN;
	int waiting LOCK_ALIGN;
	char lockname[16];
	char condname[16];
	/* page 2*/
	sem_t *lock PAGE_ALIGN;
	sem_t *cond;
};

void
xshmfence_init(int fd);
void
xshmfence_open_semaphore(struct xshmfence *f);
void
xshmfence_close_semaphore(struct xshmfence *f);

#endif /* _XSHMFENCE_SEMAPHORE_H_ */
