# $NetBSD: options.mk,v 1.4 2006/12/15 20:33:01 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fluxbox
PKG_SUPPORTED_OPTIONS=	gnome kde imlib2 xft xrender
PKG_SUGGESTED_OPTIONS=	xrender

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=        --enable-gnome
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

.if !empty(PKG_OPTIONS:Mkde)
CONFIGURE_ARGS+=        --enable-kde
.else
CONFIGURE_ARGS+=	--disable-kde
.endif

.if !empty(PKG_OPTIONS:Mimlib2)
CONFIGURE_ARGS+=	--enable-imlib2
.include "../../graphics/imlib2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-imlib2
.endif

.if !empty(PKG_OPTIONS:Mxft)
CONFIGURE_ARGS+=        --enable-xft
.include "../../x11/libXft/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

.if !empty(PKG_OPTIONS:Mxrender)
CONFIGURE_ARGS+=	--enable-xrender
.include "../../x11/libXrender/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xrender
.endif
