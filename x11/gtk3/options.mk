# $NetBSD: options.mk,v 1.17 2020/01/06 05:08:42 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtk3
PKG_SUPPORTED_OPTIONS+=	gtk3-atk-bridge cups debug
PKG_SUPPORTED_OPTIONS+=	wayland x11
.if exists(/System/Library/Frameworks/Quartz.framework)
PKG_SUPPORTED_OPTIONS+=	quartz
.endif
.include "../../devel/wayland/platform.mk"
.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS+=	wayland
.endif
PKG_SUGGESTED_OPTIONS+=	gtk3-atk-bridge x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cups
.if !empty(PKG_OPTIONS:Mcups)
BUILDLINK_API_DEPENDS.cups-base+=	cups-base>=1.7
.include "../../print/cups-base/buildlink3.mk"
PLIST.cups=		yes
.else
CONFIGURE_ENV+=		ac_cv_path_CUPS_CONFIG=no
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug=yes
.endif

PLIST_VARS+=		quartz
.if !empty(PKG_OPTIONS:Mquartz)
CONFIGURE_ARGS+=	--enable-quartz-backend
PLIST.quartz=		yes
.else
CONFIGURE_ARGS+=	--disable-quartz-backend
.endif

PLIST_VARS+=		wayland
.if !empty(PKG_OPTIONS:Mwayland)
PLIST.wayland=		yes
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-wayland-backend
.else
CONFIGURE_ARGS+=	--disable-wayland-backend
.endif

PLIST_VARS+=		x11
.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--enable-x11-backend
CONFIGURE_ENV+=		ac_cv_header_X11_extensions_Xinerama_h=no
CONFIGURE_ENV+=		ac_cv_lib_Xinerama_XineramaQueryExtension=no
PLIST.x11=		yes

.  if !empty(PKG_OPTIONS:Mgtk3-atk-bridge)
BUILDLINK_API_DEPENDS.at-spi2-atk+=	at-spi2-atk>=2.6.1
.    include "../../devel/at-spi2-atk/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--without-atk-bridge
.  endif

BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.2nb2

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-x11-backend
.endif
