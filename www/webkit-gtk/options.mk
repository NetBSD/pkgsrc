# $NetBSD: options.mk,v 1.1 2010/04/12 02:26:39 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.webkit-gtk
PKG_SUPPORTED_OPTIONS=	webkit-jit
PKG_SUGGESTED_OPTIONS=	webkit-jit

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwebkit-jit)
CONFIGURE_ARGS+=	--enable-jit
.else
CONFIGURE_ARGS+=	--disable-jit
.endif
