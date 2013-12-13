# $NetBSD: buildlink3.mk,v 1.1 2013/12/13 14:38:36 ryoon Exp $

BUILDLINK_TREE+=	qt5-qtsensors

.if !defined(QT5_QTSENSORS_BUILDLINK3_MK)
QT5_QTSENSORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtsensors+=	qt5-qtsensors>=5.2.0rc1
BUILDLINK_PKGSRCDIR.qt5-qtsensors?=	../../x11/qt5-qtsensors

BUILDLINK_INCDIRS.qt5-qtsensors+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtsensors+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtsensors+=	qt5/plugins

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_QTSENSORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtsensors
