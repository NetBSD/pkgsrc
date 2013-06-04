# $NetBSD: options.mk,v 1.1 2013/06/04 03:23:56 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xf86-video-suncg14
PKG_SUPPORTED_OPTIONS=	static
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mstatic)
CONFIGURE_ARGS+=	--enable-static=yes
.else
CONFIGURE_ARGS+=	--enable-static=no
.endif
