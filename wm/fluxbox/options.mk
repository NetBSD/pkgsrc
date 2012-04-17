# $NetBSD: options.mk,v 1.6 2012/04/17 17:13:01 bsiegert Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fluxbox
PKG_SUPPORTED_OPTIONS=	gnome kde imlib2 xft xrender nls
PKG_SUGGESTED_OPTIONS=	xrender

.include "../../mk/bsd.options.mk"

.if ${OPSYS} != "MirBSD"
PKG_SUGGESTED_OPTIONS+=	nls
.endif

PLIST_VARS+=		nls

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--enable-gnome
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

.if !empty(PKG_OPTIONS:Mkde)
CONFIGURE_ARGS+=	--enable-kde
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
CONFIGURE_ARGS+=	--enable-xft
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

.if !empty(PKG_OPTIONS:Mnls)
CONFIGURE_ARGS+=	--enable-nls
.include "../../converters/libiconv/buildlink3.mk"
PLIST.nls=		Yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
