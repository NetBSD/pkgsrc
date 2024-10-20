# $NetBSD: options.mk,v 1.27 2024/10/20 14:04:48 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtk3
PKG_SUPPORTED_OPTIONS+=	gtk3-atk-bridge cups
PKG_SUPPORTED_OPTIONS+=	wayland x11
.if exists(/System/Library/Frameworks/Quartz.framework)
PKG_SUPPORTED_OPTIONS+=	quartz
PKG_SUGGESTED_OPTIONS+=	quartz
.else
PKG_SUGGESTED_OPTIONS+=	x11
.endif
.include "../../devel/wayland/platform.mk"
.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS+=	wayland
.endif
PKG_SUGGESTED_OPTIONS+=	gtk3-atk-bridge cups

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	cups
.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/libcups/buildlink3.mk"
PLIST.cups=	yes
MESON_ARGS+=	-Dprint_backends=cups,file,lpr,test
.else
MESON_ARGS+=	-Dprint_backends=file,lpr,test
.endif

PLIST_VARS+=	quartz
.if !empty(PKG_OPTIONS:Mquartz)
PLIST.quartz=	yes
MESON_ARGS+=	-Dquartz_backend=true
.else
MESON_ARGS+=	-Dquartz_backend=false
.endif

PLIST_VARS+=	wayland
.if !empty(PKG_OPTIONS:Mwayland)
PLIST.wayland=	yes
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
MESON_ARGS+=	-Dwayland_backend=true
.else
MESON_ARGS+=	-Dwayland_backend=false
.endif

PLIST_VARS+=	x11
.if !empty(PKG_OPTIONS:Mx11)
MESON_ARGS+=	-Dx11_backend=true
MESON_ARGS+=	-Dxinerama=yes
PLIST.x11=	yes

.  if !empty(PKG_OPTIONS:Mgtk3-atk-bridge)
BUILDLINK_API_DEPENDS.at-spi2-core+=	at-spi2-core>=2.54
.    include "../../devel/at-spi2-core/buildlink3.mk"
MESON_ARGS+=	-Datk_bridge=true
.  else
MESON_ARGS+=	-Datk_bridge=false
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
MESON_ARGS+=	-Dx11_backend=false
.endif
