# $NetBSD: options.mk,v 1.2 2024/08/06 13:39:40 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.picom
PKG_SUPPORTED_OPTIONS=		dbus opengl
PKG_SUGGESTED_OPTIONS=		dbus

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular" || \
    (${OPSYS} == "NetBSD" && ${OPSYS_VERSION} >= 100000)
PKG_SUGGESTED_OPTIONS+=		opengl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
MESON_ARGS+=		-Ddbus=true
.  include "../../sysutils/dbus/buildlink3.mk"
.else
MESON_ARGS+=		-Ddbus=false
.endif

.if !empty(PKG_OPTIONS:Mopengl)
MESON_ARGS+=		-Dopengl=true
.  include "../../graphics/libepoxy/buildlink3.mk"
.else
MESON_ARGS+=		-Dopengl=false
.endif
