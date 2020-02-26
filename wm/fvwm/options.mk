# $NetBSD: options.mk,v 1.5 2020/02/26 18:09:40 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.fvwm
PKG_SUPPORTED_OPTIONS=		gtk xrender xcursor xft2 fribidi debug svg
PKG_SUGGESTED_OPTIONS+=		svg
PKG_OPTIONS_LEGACY_VARS+=	FVWM2_USE_GTK:gtk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk fribidi

.if !empty(PKG_OPTIONS:Mgtk)
.  include "../../x11/gtk/buildlink3.mk"
PLIST.gtk=		yes
.else
CONFIGURE_ARGS+=	--without-gtk-prefix
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

.if !empty(PKG_OPTIONS:Mfribidi)
CONFIGURE_ARGS+=	--enable-bidi
.include "../../converters/fribidi/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-bidi
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug-msgs
.else
CONFIGURE_ARGS+=	--disable-debug-msgs
.endif

.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/available.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-rsvg
.endif
