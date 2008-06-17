# $NetBSD: options.mk,v 1.3 2008/06/17 00:00:30 abs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.jwm
PKG_SUPPORTED_OPTIONS=	debug fribidi jpeg png
PKG_SUGGESTED_OPTIONS=	fribidi jpeg png

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mfribidi)
.include "../../converters/fribidi/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjpeg)
.include "../../graphics/jpeg/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-png
.endif
