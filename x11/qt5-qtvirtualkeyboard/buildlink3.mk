# $NetBSD: buildlink3.mk,v 1.10 2020/11/05 09:07:22 ryoon Exp $

BUILDLINK_TREE+=	qt5-qtvirtualkeyboard

.if !defined(QT5_QTVIRTUALKEYBOARD_BUILDLINK3_MK)
QT5_QTVIRTUALKEYBOARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtvirtualkeyboard+=	qt5-qtvirtualkeyboard>=5.13.2
BUILDLINK_ABI_DEPENDS.qt5-qtvirtualkeyboard?=	qt5-qtvirtualkeyboard>=5.15.1nb1
BUILDLINK_PKGSRCDIR.qt5-qtvirtualkeyboard?=	../../x11/qt5-qtvirtualkeyboard

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_QTVIRTUALKEYBOARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtvirtualkeyboard
