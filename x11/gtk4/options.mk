# $NetBSD: options.mk,v 1.1 2021/02/25 09:55:55 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtk4
PKG_SUPPORTED_OPTIONS=	cups debug

PKG_OPTIONS_REQUIRED_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		x11

.if exists(/System/Library/Frameworks/Quartz.framework)
PKG_OPTIONS_GROUP.gui+=	quartz
.endif

PKG_SUGGESTED_OPTIONS+=	cups x11

.include "../../mk/bsd.options.mk"

## wayland option requires gdk/wayland/tablet-unstable-v2-client-protocol.h
## and I cannot fint it in pkgsrc.
#PKG_SUPPORTED_OPTIONS+=	wayland
#PLIST_VARS+=		wayland
#.if !empty(PKG_OPTIONS:Mwayland)
#PLIST.wayland=		yes
#.include "../../devel/wayland/buildlink3.mk"
#.include "../../devel/wayland-protocols/buildlink3.mk"
#.include "../../fonts/fontconfig/buildlink3.mk"
#.include "../../x11/libxkbcommon/buildlink3.mk"
#MESON_ARGS+=		-Dwayland-backend=true
#.else
MESON_ARGS+=		-Dwayland-backend=false
#.endif

PLIST_VARS+=		quartz
.if !empty(PKG_OPTIONS:Mquartz)
PLIST.quartz=		yes
MESON_ARGS+=		-Dmacos-backend=true
.else
MESON_ARGS+=		-Dmacos-backend=false
.endif

PLIST_VARS+=		x11
.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes
MESON_ARGS+=		-Dx11-backend=true
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.else
MESON_ARGS+=		-Dx11-backend=false
.endif

PLIST_VARS+=		cups lpr
.if !empty(PKG_OPTIONS:Mcups)
PLIST.cups=		yes
MESON_ARGS+=		-Dprint-cups=enabled
.include "../../print/libcups/buildlink3.mk"
.else
PLIST.lpr=		yes
MESON_ARGS+=		-Dprint-cups=disabled
.endif

.if !empty(PKG_OPTIONS:Mdebug)
MESON_ARGS+=		-Ddebug=true
.else
MESON_ARGS+=		-Ddebug=false
.endif
