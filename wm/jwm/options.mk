# $NetBSD: options.mk,v 1.6 2016/10/10 13:22:22 tsutsui Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.jwm
PKG_SUPPORTED_OPTIONS=	debug fribidi jpeg png svg
PKG_SUGGESTED_OPTIONS=	fribidi jpeg png svg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mfribidi)
.include "../../converters/fribidi/buildlink3.mk"
BUILDLINK_API_DEPENDS.fribidi+=   fribidi>=0.19.2
.else
CONFIGURE_ARGS+=	--disable-fribidi
.endif

.if !empty(PKG_OPTIONS:Mjpeg)
.include "../../mk/jpeg.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-jpeg
.endif

.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-png
.endif

.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-rsvg
.endif
