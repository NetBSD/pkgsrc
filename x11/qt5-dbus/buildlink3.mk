# $NetBSD: buildlink3.mk,v 1.3 2014/02/03 16:17:12 ryoon Exp $

BUILDLINK_TREE+=	qt5-dbus

.if !defined(QT5_DBUS_BUILDLINK3_MK)
QT5_DBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-dbus+=	qt5-dbus>=5.2.0
BUILDLINK_ABI_DEPENDS.qt5-dbus?=	qt5-dbus>=5.2.0nb2
BUILDLINK_PKGSRCDIR.qt5-dbus?=	../../x11/qt5-dbus

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QT5_DBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-dbus
