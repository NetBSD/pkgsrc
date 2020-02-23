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

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "xshmfenceint.h"

static sem_t *mksemtemp(char *, size_t, const char *);

#define COND_WAIT_W() do {} while (sem_wait(f->cond_w) != 0)
#define COND_SIGNAL_W() do { sem_post(f->cond_w); } while (0)
#define COND_WAIT_T() do {} while (sem_wait(f->cond_t) != 0)
#define COND_SIGNAL_T() do { sem_post(f->cond_t); } while (0)

/**
 * xshmfence_trigger:
 * @f: An X fence
 *
 * Set @f to triggered, waking all waiters.
 *
 * Return value: 0 on success and -1 on error (in which case, errno
 * will be set as appropriate).
 **/
int
xshmfence_trigger(struct xshmfence *f) {
	int v, waiting;
	v = __sync_bool_compare_and_swap(&f->triggered, 0, 1);
	if (v == 0) {
		/* already triggered */
		return 0;
	}

	while ((waiting = __sync_fetch_and_add(&f->waiting, 0)) > 0) {
		if (__sync_bool_compare_and_swap(&f->waiting, waiting, 0)) {
			__sync_fetch_and_add(&f->wakeups, waiting);
			while (waiting--) {
				COND_SIGNAL_W();
			}
			COND_WAIT_T();
			return 0;
		}
	}

	return 0;
}

/**
 * xshmfence_await:
 * @f: An X fence
 *
 * Wait for @f to be triggered. If @f is already triggered, this
 * function returns immediately.
 *
 * Return value: 0 on success and -1 on error (in which case, errno
 * will be set as appropriate).
 **/
int
xshmfence_await(struct xshmfence *f) {

	if (__sync_fetch_and_add(&f->triggered, 0) == 1) {
		return 0;
	}
	do {
		__sync_fetch_and_add(&f->waiting, 1);
		COND_WAIT_W();
	} while (__sync_fetch_and_add(&f->triggered, 0) == 0);

	if (__sync_sub_and_fetch(&f->wakeups, 1) == 0) {
		COND_SIGNAL_T();
	}

	return 0;
}

/**
 * xshmfence_query:
 * @f: An X fence
 *
 * Return value: 1 if @f is triggered, else returns 0.
 **/
int
xshmfence_query(struct xshmfence *f) {
	return __sync_fetch_and_add(&f->triggered, 0);
}

/**
 * xshmfence_reset:
 * @f: An X fence
 *
 * Reset @f to untriggered. If @f is already untriggered,
 * this function has no effect.
 **/
void
xshmfence_reset(struct xshmfence *f) {
	__sync_bool_compare_and_swap(&f->triggered, 1, 0);
}

/**
 * xshmfence_init:
 * @fd: An fd for an X fence
 *
 * Initialize the fence when first allocated
 **/
void
xshmfence_init(int fd)
{
	sem_t *cond_w, *cond_t;
	struct xshmfence f;

	__sync_fetch_and_and(&f.refcnt, 0);
	__sync_fetch_and_and(&f.triggered, 0);
	__sync_fetch_and_and(&f.waiting, 0);
	__sync_fetch_and_and(&f.wakeups, 0);

	cond_w = mksemtemp(f.condname_w, sizeof(f.condname_w), "w");
	if (cond_w == SEM_FAILED) {
		err(EXIT_FAILURE, "xshmfence_init: sem_open");
	}
	cond_t = mksemtemp(f.condname_t, sizeof(f.condname_t), "t");
	if (cond_t == SEM_FAILED) {
		err(EXIT_FAILURE, "xshmfence_init: sem_open");
	}

	sem_close(cond_w);
	sem_close(cond_t);

	pwrite(fd, &f, sizeof(f), 0);
}

/**
 * xshmfence_open_semaphore:
 * @f: An X fence
 *
 * Open the semaphore after mapping the fence
 **/
void
xshmfence_open_semaphore(struct xshmfence *f)
{
	/*
	 * map process local memory to page 2
	 */
	if (mmap ((void*)&f->cond_w,
		  LIBXSHM_PAGESIZE,
		  PROT_READ|PROT_WRITE,
		  MAP_FIXED|MAP_ANON,
		  -1, 0) == MAP_FAILED) {
		errx(EXIT_FAILURE, "xshmfence_open_semaphore: mmap failed");
	}

	if ((f->cond_w = sem_open(f->condname_w, 0)) == SEM_FAILED) {
		errx(EXIT_FAILURE, "xshmfence_open_semaphore: sem_open failed");
	}

	if ((f->cond_t = sem_open(f->condname_t, 0)) == SEM_FAILED) {
		errx(EXIT_FAILURE, "xshmfence_open_semaphore: sem_open failed");
	}
	__sync_fetch_and_add(&f->refcnt, 1);
}

/**
 * xshmfence_close_semaphore:
 * @f: An X fence
 *
 * Close the semaphore before unmapping the fence
 **/
void
xshmfence_close_semaphore(struct xshmfence *f)
{
	sem_close(f->cond_w);
	sem_close(f->cond_t);
	if (__sync_sub_and_fetch(&f->refcnt, 1) == 0) {
		sem_unlink(f->condname_w);
		sem_unlink(f->condname_t);
	}
}

static sem_t *
mksemtemp(char *name, size_t namelen, const char *suffix)
{
	sem_t *ret;
	pid_t p;
	p = getpid();
	for(;;) {
		if (snprintf(name, namelen, "/xshmf%s-%d", suffix, p) >= namelen)
			return SEM_FAILED;
		ret = sem_open(name, O_CREAT|O_EXCL, 0600, 0);
		if (ret == SEM_FAILED) {
			if (errno == EEXIST) {
				p++;
				continue;
			}
		}
		return ret;
	}
}
