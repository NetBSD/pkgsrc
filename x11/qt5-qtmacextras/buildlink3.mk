# $NetBSD: buildlink3.mk,v 1.5 2016/03/05 11:28:00 jperkin Exp $

BUILDLINK_TREE+=	qt5-qtmacextras

.if !defined(QT5_QTMACEXTRAS_BUILDLINK3_MK)
QT5_QTMACEXTRAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtmacextras+=	qt5-qtmacextras>=5.5.1
BUILDLINK_ABI_DEPENDS.qt5-qtmacextras+=	qt5-qtmacextras>=5.5.1nb2
BUILDLINK_PKGSRCDIR.qt5-qtmacextras?=	../../x11/qt5-qtmacextras

BUILDLINK_INCDIRS.qt5-qtmacextras+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtmacextras+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtmacextras+=	qt5/plugins

.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.endif	# QT5_QTMACEXTRAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtmacextras
