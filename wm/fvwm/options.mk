# $NetBSD: options.mk,v 1.2 2013/01/20 06:53:53 mef Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.fvwm
PKG_SUPPORTED_OPTIONS=		gtk rplay xrender xcursor xft2
PKG_OPTIONS_LEGACY_VARS+=	FVWM2_USE_GTK:gtk
PKG_OPTIONS_LEGACY_VARS+=	FVWM2_USE_RPLAY:rplay

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk

.if !empty(PKG_OPTIONS:Mgtk)
.  include "../../x11/gtk/buildlink3.mk"
PLIST.gtk=		yes
.else
CONFIGURE_ARGS+=	--without-gtk-prefix
.endif

.if !empty(PKG_OPTIONS:Mrplay)
.  include "../../audio/rplay/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mxcursor)
CONFIGURE_ARGS+=	--enable-xcursor
.include "../../x11/libXcursor/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xcursor
.endif

.if !empty(PKG_OPTIONS:Mxft2)
CONFIGURE_ARGS+=        --enable-xft
.include "../../x11/libXft/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-xft
.endif

.if !empty(PKG_OPTIONS:Mxrender)
CONFIGURE_ARGS+=        --enable-xrender
.include "../../x11/libXrender/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-xrender
.endif
