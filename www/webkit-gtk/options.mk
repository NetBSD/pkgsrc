# $NetBSD: options.mk,v 1.2 2013/02/02 12:00:20 jmcneill Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.webkit-gtk
PKG_SUPPORTED_OPTIONS=	webkit-jit debug
PKG_SUGGESTED_OPTIONS=	webkit-jit

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwebkit-jit)
CONFIGURE_ARGS+=	--enable-jit
.else
CONFIGURE_ARGS+=	--disable-jit
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif
