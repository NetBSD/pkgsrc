# $NetBSD: options.mk,v 1.2 2005/03/30 11:59:10 jmcneill Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fluxbox
PKG_SUPPORTED_OPTIONS=	gnome kde imlib2 xft

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
.include "../../fonts/Xft2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xft
.endif
