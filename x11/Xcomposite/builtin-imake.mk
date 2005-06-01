XCOMM $NetBSD: builtin-imake.mk,v 1.1 2005/06/01 18:03:27 jlam Exp $

/*
 * Check the value of BuildCompositeLibrary for the presence of
 * Xcomposite in the X11 distribution.
 */
builtin-test:
#if BuildCompositeLibrary
	@echo yes
#else
	@echo no
#endif
