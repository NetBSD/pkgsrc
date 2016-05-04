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

static sem_t *mksemtemp(char *, const char *);

#define LOCK() do {} while (sem_wait(f->lock) != 0)
#define UNLOCK() do { sem_post(f->lock); } while (0)
#define COND_WAIT() do {} while (sem_wait(f->cond) != 0)
#define COND_SIGNAL() do { sem_post(f->cond); } while (0)

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
	LOCK();
	v = __sync_bool_compare_and_swap(&f->triggered, 0, 1);
	if (v == 0) {
		/* already triggered */
		UNLOCK();
		return 0;
	}
	
	waiting = __sync_fetch_and_add(&f->waiting, 0);

	while (waiting > 0) {
		COND_SIGNAL();
		waiting--;
	}

	while (__sync_fetch_and_add(&f->waiting, 0) > 0) {
		/*
		 * Busy wait until they all woke up.
		 * No new sleepers should arrive since
		 * the lock is still held.
		 */
		/* yield(); */
	}
	UNLOCK();
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

	LOCK();
	if (__sync_fetch_and_add(&f->triggered, 0) == 1) {
		UNLOCK();
		return 0;
	}
	do {
		__sync_fetch_and_add(&f->waiting, 1);
		/*
		 * These next operations are not atomic.
		 * But we busy-wait in xshmfence_trigger, so that's ok.
		 */
		UNLOCK();
		COND_WAIT();
		__sync_fetch_and_sub(&f->waiting, 1);
		LOCK();
	}
	while (__sync_fetch_and_add(&f->triggered, 0) == 0);
	UNLOCK();
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
	int ret;
	LOCK();
	ret = __sync_fetch_and_add(&f->triggered, 0);
	UNLOCK();
	return ret;
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
	LOCK();
	__sync_bool_compare_and_swap(&f->triggered, 1, 0);
	UNLOCK();
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
	sem_t *lock;
	sem_t *cond;
	struct xshmfence f;

	__sync_fetch_and_and(&f.refcnt, 0);
	__sync_fetch_and_and(&f.triggered, 0);
	__sync_fetch_and_and(&f.waiting, 0);
	
	lock = mksemtemp(f.lockname, "/xshmfl-%i");
	if (lock == SEM_FAILED) {
		err(EXIT_FAILURE, "xshmfence_init: sem_open");
	}

	cond = mksemtemp(f.condname, "/xshmfc-%i");
	if (cond == SEM_FAILED) {
		err(EXIT_FAILURE, "xshmfence_init: sem_open");
	}
	
	sem_close(lock);
	sem_close(cond);
	
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
	if (mmap ((void*)&f->lock,
		  LIBXSHM_PAGESIZE,
		  PROT_READ|PROT_WRITE,
		  MAP_FIXED|MAP_ANON,
		  -1, 0) == MAP_FAILED) {
		errx(EXIT_FAILURE, "xshmfence_open_semaphore: mmap failed");
	}

	if ((f->lock = sem_open(f->lockname, 0 , 0)) == SEM_FAILED) {
		errx(EXIT_FAILURE, "xshmfence_open_semaphore: sem_open failed");
	}

	if ((f->cond = sem_open(f->condname, 0 , 0)) == SEM_FAILED) {
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
	sem_close(f->lock);
	sem_close(f->cond);
	if (__sync_sub_and_fetch(&f->refcnt, 1) == 0) {
		sem_unlink(f->lockname);
		sem_unlink(f->condname);
	}
}

static sem_t *
mksemtemp(char *name, const char *template)
{
	sem_t *ret;
	pid_t p;
	p = getpid();
	for(;;) {
		sprintf(name, template, p);
		ret = sem_open(name, O_CREAT|O_EXCL, 0600, 1);
		if (ret == SEM_FAILED) {
			if (errno == EEXIST) {
				p++;
				continue;
			}
		}
		return ret;
	}
}
