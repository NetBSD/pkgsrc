# $NetBSD: buildlink3.mk,v 1.21 2026/04/28 08:04:06 pin Exp $

BUILDLINK_TREE+=	qtermwidget

.if !defined(QTERMWIDGET_BUILDLINK3_MK)
QTERMWIDGET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qtermwidget+=	qtermwidget>=2.1.0
BUILDLINK_ABI_DEPENDS.qtermwidget?=	qtermwidget>=2.4.0
BUILDLINK_PKGSRCDIR.qtermwidget?=	../../x11/qtermwidget

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QTERMWIDGET_BUILDLINK3_MK

BUILDLINK_TREE+=	-qtermwidget
