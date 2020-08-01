# $NetBSD: options.mk,v 1.1 2020/08/01 07:18:35 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-qt4
PKG_SUPPORTED_OPTIONS=	dbus
PKG_SUGGESTED_OPTIONS+=	dbus

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	dbus
.if !empty(PKG_OPTIONS:Mdbus)
PLIST.dbus=	yes
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.else
post-extract:
	rm -rf ${WRKSRC}/dbus
.endif
