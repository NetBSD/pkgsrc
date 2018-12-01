# $NetBSD: options.mk,v 1.1 2018/12/01 13:23:51 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.compton
PKG_SUPPORTED_OPTIONS=	dbus libdrm opengl pcre
PKG_SUGGESTED_OPTIONS=	dbus libdrm opengl pcre

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus/buildlink3.mk"
.else
MAKE_FLAGS+=	NO_DBUS=1
.endif

.if !empty(PKG_OPTIONS:Mlibdrm)
.include "../../x11/libdrm/buildlink3.mk"
.else
MAKE_FLAGS+=	NO_VSYNC_DRM=1
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
.else
MAKE_FLAGS+=	NO_OPENGL=1
.endif

.if !empty(PKG_OPTIONS:Mpcre)
.include "../../devel/pcre/buildlink3.mk"
.else
MAKE_FLAGS+=	NO_REGEX_PCRE=1
.endif
