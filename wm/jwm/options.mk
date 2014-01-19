# $NetBSD: options.mk,v 1.5 2014/01/19 15:27:16 tsutsui Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.jwm
PKG_SUPPORTED_OPTIONS=	debug fribidi jpeg png
PKG_SUGGESTED_OPTIONS=	fribidi jpeg png

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mfribidi)
.include "../../converters/fribidi/buildlink3.mk"
BUILDLINK_API_DEPENDS.fribidi+=   fribidi>=0.19.2
.endif

.if !empty(PKG_OPTIONS:Mjpeg)
.include "../../mk/jpeg.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-png
.endif
