# $NetBSD: options.mk,v 1.7 2021/11/14 18:42:27 tsutsui Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.jwm
PKG_SUPPORTED_OPTIONS=	debug cairo jpeg png svg
PKG_SUGGESTED_OPTIONS=	cairo jpeg png svg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mcairo)
.include "../../graphics/cairo/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-cairo
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
