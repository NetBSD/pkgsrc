# $NetBSD: options.mk,v 1.2 2019/10/21 15:56:53 pho Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.compton
PKG_SUPPORTED_OPTIONS=	dbus libdrm opengl pcre
PKG_SUGGESTED_OPTIONS=	dbus libdrm opengl pcre

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus/buildlink3.mk"
.else
MESON_ARGS+=	-Ddbus=false
.endif

.if !empty(PKG_OPTIONS:Mlibdrm)
.include "../../x11/libdrm/buildlink3.mk"
.else
MESON_ARGS+=	-Dvsync_drm=false
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
.else
MESON_ARGS+=	-Dopengl=false
.endif

.if !empty(PKG_OPTIONS:Mpcre)
.include "../../devel/pcre/buildlink3.mk"
.else
MESON_ARGS+=	-Dregex=false
.endif
