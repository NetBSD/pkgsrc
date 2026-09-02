# $NetBSD: buildlink3.mk,v 1.38 2026/09/02 19:05:28 wiz Exp $

BUILDLINK_TREE+=	qt5-qtquickcontrols2

.if !defined(QT5_QTQUICKCONTROLS2_BUILDLINK3_MK)
QT5_QTQUICKCONTROLS2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtquickcontrols2+=	qt5-qtquickcontrols2>=5.10.0
BUILDLINK_ABI_DEPENDS.qt5-qtquickcontrols2?=	qt5-qtquickcontrols2>=5.15.19nb1
BUILDLINK_PKGSRCDIR.qt5-qtquickcontrols2?=	../../x11/qt5-qtquickcontrols2

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_QTQUICKCONTROLS2_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtquickcontrols2
