XCOMM $NetBSD: builtin-imake.mk,v 1.1 2005/06/01 18:03:27 jlam Exp $

/*
 * Check the value of BuildXfixesLibrary for the presence of
 * Xfixes in the X11 distribution.
 */
builtin-test:
#if BuildXfixesLibrary
	@echo yes
#else
	@echo no
#endif
