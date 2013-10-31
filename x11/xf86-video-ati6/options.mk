# $NetBSD: options.mk,v 1.2 2013/10/31 00:07:23 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xf86-video-ati6
PKG_SUPPORTED_OPTIONS=	xf86-video-ati6-kms
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxf86-video-ati6-kms)
CONFIGURE_ARGS+=	--enable-kms
.else
CONFIGURE_ARGS+=	--disable-kms
.endif
