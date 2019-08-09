# $NetBSD: buildlink3.mk,v 1.26 2019/08/09 17:41:41 adam Exp $

BUILDLINK_TREE+=	qt5-qtsensors

.if !defined(QT5_QTSENSORS_BUILDLINK3_MK)
QT5_QTSENSORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtsensors+=	qt5-qtsensors>=5.9.1
BUILDLINK_ABI_DEPENDS.qt5-qtsensors+=	qt5-qtsensors>=5.13.0
BUILDLINK_PKGSRCDIR.qt5-qtsensors?=	../../x11/qt5-qtsensors

BUILDLINK_INCDIRS.qt5-qtsensors+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtsensors+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtsensors+=	qt5/plugins

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_QTSENSORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtsensors
