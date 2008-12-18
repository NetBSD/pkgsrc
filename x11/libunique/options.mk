# $NetBSD: options.mk,v 1.1.1.1 2008/12/18 00:32:14 ahoka Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libunique

PKG_SUPPORTED_OPTIONS=		dbus
PKG_SUGGESTED_OPTIONS=		dbus

.include "../../mk/bsd.options.mk"

#
# D-BUS support
#
.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-dbus
.  include "../../sysutils/dbus-glib/buildlink3.mk"
.endif
