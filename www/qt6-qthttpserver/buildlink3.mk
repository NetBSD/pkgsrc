# $NetBSD: buildlink3.mk,v 1.12 2024/11/14 22:22:10 wiz Exp $

BUILDLINK_TREE+=	qt6-qthttpserver

.if !defined(QT6_QTHTTPSERVER_BUILDLINK3_MK)
QT6_QTHTTPSERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qthttpserver+=	qt6-qthttpserver>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qthttpserver+=	qt6-qthttpserver>=6.8.0nb3
BUILDLINK_PKGSRCDIR.qt6-qthttpserver?=		../../www/qt6-qthttpserver

.include "../../net/qt6-qtwebsockets/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTHTTPSERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qthttpserver
