# $NetBSD: options.mk,v 1.1 2005/03/24 15:00:40 jmcneill Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fluxbox
PKG_SUPPORTED_OPTIONS=	gnome kde imlib2 xft

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=        --enable-gnome
.include "../../devel/libgnome/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

.if !empty(PKG_OPTIONS:Mkde)
CONFIGURE_ARGS+=        --enable-kde
.include "../../x11/kdelibs3/buildlink3.mk"
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
