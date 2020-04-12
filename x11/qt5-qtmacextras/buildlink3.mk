# $NetBSD: buildlink3.mk,v 1.27 2020/04/12 08:28:15 adam Exp $

BUILDLINK_TREE+=	qt5-qtmacextras

.if !defined(QT5_QTMACEXTRAS_BUILDLINK3_MK)
QT5_QTMACEXTRAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtmacextras+=	qt5-qtmacextras>=5.9.1
BUILDLINK_ABI_DEPENDS.qt5-qtmacextras+=	qt5-qtmacextras>=5.14.2nb1
BUILDLINK_PKGSRCDIR.qt5-qtmacextras?=	../../x11/qt5-qtmacextras

BUILDLINK_INCDIRS.qt5-qtmacextras+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtmacextras+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtmacextras+=	qt5/plugins

.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.endif	# QT5_QTMACEXTRAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtmacextras
