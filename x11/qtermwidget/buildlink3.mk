# $NetBSD: buildlink3.mk,v 1.19 2026/01/07 08:49:47 wiz Exp $

BUILDLINK_TREE+=	qtermwidget

.if !defined(QTERMWIDGET_BUILDLINK3_MK)
QTERMWIDGET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qtermwidget+=	qtermwidget>=2.1.0
BUILDLINK_ABI_DEPENDS.qtermwidget?=	qtermwidget>=2.3.0nb2
BUILDLINK_PKGSRCDIR.qtermwidget?=	../../x11/qtermwidget

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QTERMWIDGET_BUILDLINK3_MK

BUILDLINK_TREE+=	-qtermwidget
