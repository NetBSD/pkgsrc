# $NetBSD: options.mk,v 1.1 2019/12/15 14:05:47 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.picom
PKG_SUPPORTED_OPTIONS=		dbus opengl
PKG_SUGGESTED_OPTIONS=		dbus opengl
#PKG_SUGGESTED_OPTIONS=		dbus

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
MESON_ARGS+=		-Ddbus=true
.  include "../../sysutils/dbus/buildlink3.mk"
.else
MESON_ARGS+=		-Ddbus=false
.endif

.if !empty(PKG_OPTIONS:Mopengl)
MESON_ARGS+=		-Dopengl=true
.else
MESON_ARGS+=		-Dopengl=false
.endif
