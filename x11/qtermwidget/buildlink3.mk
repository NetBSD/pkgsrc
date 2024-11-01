# $NetBSD: buildlink3.mk,v 1.13 2024/11/01 12:55:16 wiz Exp $

BUILDLINK_TREE+=	qtermwidget

.if !defined(QTERMWIDGET_BUILDLINK3_MK)
QTERMWIDGET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qtermwidget+=	qtermwidget>=2.0.0
BUILDLINK_ABI_DEPENDS.qtermwidget?=	qtermwidget>=2.0.1nb2
BUILDLINK_PKGSRCDIR.qtermwidget?=	../../x11/qtermwidget

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QTERMWIDGET_BUILDLINK3_MK

BUILDLINK_TREE+=	-qtermwidget
