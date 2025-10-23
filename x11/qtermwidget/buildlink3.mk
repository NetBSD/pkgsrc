# $NetBSD: buildlink3.mk,v 1.18 2025/10/23 20:40:18 wiz Exp $

BUILDLINK_TREE+=	qtermwidget

.if !defined(QTERMWIDGET_BUILDLINK3_MK)
QTERMWIDGET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qtermwidget+=	qtermwidget>=2.1.0
BUILDLINK_ABI_DEPENDS.qtermwidget?=	qtermwidget>=2.2.0nb1
BUILDLINK_PKGSRCDIR.qtermwidget?=	../../x11/qtermwidget

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QTERMWIDGET_BUILDLINK3_MK

BUILDLINK_TREE+=	-qtermwidget
