# $NetBSD: buildlink3.mk,v 1.35 2023/05/22 21:00:15 wiz Exp $

BUILDLINK_TREE+=	qt5-qtwebsockets

.if !defined(QT5_WEBSOCKETS_BUILDLINK3_MK)
QT5_WEBSOCKETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtwebsockets+=	qt5-qtwebsockets>=5.9.1
BUILDLINK_ABI_DEPENDS.qt5-qtwebsockets+=	qt5-qtwebsockets>=5.15.9nb2
BUILDLINK_PKGSRCDIR.qt5-qtwebsockets?=		../../x11/qt5-qtwebsockets

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_WEBSOCKETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtwebsockets
