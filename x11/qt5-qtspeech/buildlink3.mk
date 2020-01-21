# $NetBSD: buildlink3.mk,v 1.7 2020/01/21 20:25:39 adam Exp $

BUILDLINK_TREE+=	qt5-qtspeech

.if !defined(QT5_QTSPEECH_BUILDLINK3_MK)
QT5_QTSPEECH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtspeech+=	qt5-qtspeech>=5.13.1
BUILDLINK_ABI_DEPENDS.qt5-qtspeech?=	qt5-qtspeech>=5.14.0
BUILDLINK_PKGSRCDIR.qt5-qtspeech?=	../../x11/qt5-qtspeech

BUILDLINK_INCDIRS.qt5-qtspeech+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtspeech+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtspeech+=	qt5/plugins

.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.endif	# QT5_QTSPEECH_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtspeech
