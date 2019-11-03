# $NetBSD: buildlink3.mk,v 1.5 2019/11/03 09:14:16 rillig Exp $

BUILDLINK_TREE+=	qt5-qtspeech

.if !defined(QT5_QTSPEECH_BUILDLINK3_MK)
QT5_QTSPEECH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtspeech+=	qt5-qtspeech>=5.13.1
BUILDLINK_ABI_DEPENDS.qt5-qtspeech?=	qt5-qtspeech>=5.13.1nb1
BUILDLINK_PKGSRCDIR.qt5-qtspeech?=	../../x11/qt5-qtspeech

BUILDLINK_INCDIRS.qt5-qtspeech+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtspeech+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtspeech+=	qt5/plugins

.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.endif	# QT5_QTSPEECH_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtspeech
