XCOMM $NetBSD: builtin-imake.mk,v 1.1 2005/06/01 18:03:32 jlam Exp $

/*
 * Check the value of BuildXcursorLibrary for the presence of
 * Xcursor in the X11 distribution.
 */
builtin-test:
#if BuildXcursorLibrary
	@echo yes
#else
	@echo no
#endif
