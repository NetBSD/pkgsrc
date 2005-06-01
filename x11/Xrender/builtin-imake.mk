XCOMM $NetBSD: builtin-imake.mk,v 1.1 2005/06/01 18:03:27 jlam Exp $

/*
 * Check the value of BuildRenderLibrary for the presence of
 * Xrender in the X11 distribution.
 */
builtin-test:
#if BuildRenderLibrary
	@echo yes
#else
	@echo no
#endif
