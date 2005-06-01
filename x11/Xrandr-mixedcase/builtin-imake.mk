XCOMM $NetBSD: builtin-imake.mk,v 1.1 2005/06/01 18:03:27 jlam Exp $

/*
 * Check the value of BuildRandRLibrary for the presence of
 * Xrandr in the X11 distribution.
 */
builtin-test:
#if BuildRandRLibrary
	@echo yes
#else
	@echo no
#endif
