# $NetBSD: buildlink3.mk,v 1.15 2022/11/23 16:19:12 adam Exp $

BUILDLINK_TREE+=	qt5-qtconnectivity

.if !defined(QT5_QTCONNECTIVITY_BUILDLINK3_MK)
QT5_QTCONNECTIVITY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtconnectivity+=	qt5-qtconnectivity>=5.12.2
BUILDLINK_ABI_DEPENDS.qt5-qtconnectivity?=	qt5-qtconnectivity>=5.15.7nb1
BUILDLINK_PKGSRCDIR.qt5-qtconnectivity?=	../../x11/qt5-qtconnectivity

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_QTCONNECTIVITY_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtconnectivity
