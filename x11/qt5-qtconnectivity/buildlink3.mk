# $NetBSD: buildlink3.mk,v 1.19 2023/10/24 22:11:45 wiz Exp $

BUILDLINK_TREE+=	qt5-qtconnectivity

.if !defined(QT5_QTCONNECTIVITY_BUILDLINK3_MK)
QT5_QTCONNECTIVITY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtconnectivity+=	qt5-qtconnectivity>=5.12.2
BUILDLINK_ABI_DEPENDS.qt5-qtconnectivity?=	qt5-qtconnectivity>=5.15.11nb1
BUILDLINK_PKGSRCDIR.qt5-qtconnectivity?=	../../x11/qt5-qtconnectivity

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_QTCONNECTIVITY_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtconnectivity
