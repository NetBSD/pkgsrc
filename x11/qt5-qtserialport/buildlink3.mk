# $NetBSD: buildlink3.mk,v 1.10 2016/03/05 11:28:01 jperkin Exp $

BUILDLINK_TREE+=	qt5-qtserialport

.if !defined(QT5_QTSERIALPORT_BUILDLINK3_MK)
QT5_QTSERIALPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtserialport+=	qt5-qtserialport>=5.5.1
BUILDLINK_ABI_DEPENDS.qt5-qtserialport+=	qt5-qtserialport>=5.5.1nb2
BUILDLINK_PKGSRCDIR.qt5-qtserialport?=	../../x11/qt5-qtserialport

BUILDLINK_INCDIRS.qt5-qtserialport+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtserialport+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtserialport+=	qt5/plugins

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QT5_QTSERIALPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtserialport
