# $NetBSD: options.mk,v 1.1.1.1 2006/03/30 19:15:47 ghen Exp $

PKG_OPTIONS_VAR		= PKG_OPTIONS.gecko
PKG_SUPPORTED_OPTIONS	= debug

.include "../../mk/bsd.options.mk"

# this .if test looks backward, but the missing options disables debug,
# so it is correct
.if empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--disable-debug
.endif
