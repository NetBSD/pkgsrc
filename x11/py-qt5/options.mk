# $NetBSD: options.mk,v 1.1 2022/12/02 15:31:58 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-qt5
PKG_SUPPORTED_OPTIONS+=	dbus
PKG_SUGGESTED_OPTIONS+=	dbus

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dbus
.if !empty(PKG_OPTIONS:Mdbus)
PLIST.dbus=		yes
.include "../../sysutils/dbus-python-common/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.endif
