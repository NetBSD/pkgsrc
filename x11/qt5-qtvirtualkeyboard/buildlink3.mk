# $NetBSD: buildlink3.mk,v 1.17 2023/11/08 13:21:39 wiz Exp $

BUILDLINK_TREE+=	qt5-qtvirtualkeyboard

.if !defined(QT5_QTVIRTUALKEYBOARD_BUILDLINK3_MK)
QT5_QTVIRTUALKEYBOARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtvirtualkeyboard+=	qt5-qtvirtualkeyboard>=5.13.2
BUILDLINK_ABI_DEPENDS.qt5-qtvirtualkeyboard?=	qt5-qtvirtualkeyboard>=5.15.11nb2
BUILDLINK_PKGSRCDIR.qt5-qtvirtualkeyboard?=	../../x11/qt5-qtvirtualkeyboard

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_QTVIRTUALKEYBOARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtvirtualkeyboard
