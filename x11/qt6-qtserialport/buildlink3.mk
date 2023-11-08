# $NetBSD: buildlink3.mk,v 1.6 2023/11/08 13:21:40 wiz Exp $

BUILDLINK_TREE+=	qt6-qtserialport

.if !defined(QT6_QTSERIALPORT_BUILDLINK3_MK)
QT6_QTSERIALPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtserialport+=	qt6-qtserialport>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtserialport+=	qt6-qtserialport>=6.6.0nb1
BUILDLINK_PKGSRCDIR.qt6-qtserialport?=		../../x11/qt6-qtserialport

BUILDLINK_INCDIRS.qt6-qtserialport+=	qt6/include
BUILDLINK_LIBDIRS.qt6-qtserialport+=	qt6/lib
BUILDLINK_LIBDIRS.qt6-qtserialport+=	qt6/plugins

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTSERIALPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtserialport
