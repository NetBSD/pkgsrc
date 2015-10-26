# $NetBSD: buildlink3.mk,v 1.4 2015/10/26 19:04:01 adam Exp $

BUILDLINK_TREE+=	qt5-websockets

.if !defined(QT5_WEBSOCKETS_BUILDLINK3_MK)
QT5_WEBSOCKETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-websockets+=	qt5-websockets>=5.5.1
BUILDLINK_ABI_DEPENDS.qt5-websockets+=	qt5-websockets>=5.5.1
BUILDLINK_PKGSRCDIR.qt5-websockets?=	../../x11/qt5-qtwebsockets

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_WEBSOCKETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-websockets
