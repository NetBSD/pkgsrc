# $NetBSD: options.mk,v 1.1.1.1 2006/08/04 01:08:21 reed Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.jwm
PKG_SUPPORTED_OPTIONS=	debug png
PKG_SUGGESTED_OPTIONS=	png

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-png
.endif

# TODO: fribidi
