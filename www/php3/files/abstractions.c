/*	$NetBSD: abstractions.c,v 1.1 1999/05/03 19:45:44 tv Exp $	*/

/*
 * This provides abstracted definitions for a few functions that are
 * "inlined" in normal statically-compiled PHP modules.  This way, any
 * dynamic module can be used with any PHP server interface (CGI, Apache, ...).
 */

#define PHP_INTERNAL_FUNCS 1
#include "php.h"

void _php3_puts(const char *s) {
	PUTS(s);
}

void _php3_putc(char c) {
	PUTC(c);
}

int _php3_write(const void *a, int n) {
	PHPWRITE(a, n);
}

void _php3_block_interruptions(void) {
	BLOCK_INTERRUPTIONS;
}

void _php3_unblock_interruptions(void) {
	UNBLOCK_INTERRUPTIONS;
}
