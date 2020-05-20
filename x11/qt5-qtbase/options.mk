# $NetBSD: options.mk,v 1.16 2020/05/20 11:52:58 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qt5
PKG_SUPPORTED_OPTIONS+=	cups dbus gtk3
PKG_SUGGESTED_OPTIONS+=	cups dbus

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cups
.if !empty(PKG_OPTIONS:Mcups)
.  include "../../print/libcups/buildlink3.mk"
CONFIGURE_ARGS+=	-cups
PLIST.cups=		yes
.else
CONFIGURE_ARGS+=	-no-cups
.endif

PLIST_VARS+=		dbus
.if !empty(PKG_OPTIONS:Mdbus)
PC_FILES+=		Qt5DBus.pc
# Use lib/dbus-1.0/include/dbus/dbus-arch-deps.h from sysutils/dbus
USE_DBUS-ARCH-DEPS_H=	yes
.include "../../sysutils/dbus/buildlink3.mk"
CONFIGURE_ARGS+=	-dbus-linked
PLIST.dbus=		yes
.else
CONFIGURE_ARGS+=	-no-dbus
.endif

PLIST_VARS+=		gtk3
.if !empty(PKG_OPTIONS:Mgtk3)
.  include "../../x11/gtk3/buildlink3.mk"
CONFIGURE_ARGS+=	-gtk
PLIST.gtk3=		yes
.else
CONFIGURE_ARGS+=	-no-gtk
.endif
