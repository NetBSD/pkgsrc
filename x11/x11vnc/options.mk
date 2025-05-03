# $NetBSD: options.mk,v 1.7 2025/05/03 16:51:15 nia Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.x11vnc
PKG_SUPPORTED_OPTIONS=	avahi libdrm x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../graphics/MesaLib/features.mk"

.if ${MESALIB_SUPPORTS_DRI:tl} != "no"
PKG_SUGGESTED_OPTIONS+=	libdrm
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
CONFIGURE_ARGS+=	--with-avahi=${BUILDLINK_PREFIX.avahi}
.else
CONFIGURE_ARGS+=	--without-avahi
.endif

.if !empty(PKG_OPTIONS:Mlibdrm)
.include "../../x11/libdrm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-drm
.else
CONFIGURE_ARGS+=	--without-drm
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=		--with-x
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
