# $NetBSD: buildlink3.mk,v 1.8 2022/06/28 11:37:59 wiz Exp $

BUILDLINK_TREE+=	qtermwidget

.if !defined(QTERMWIDGET_BUILDLINK3_MK)
QTERMWIDGET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qtermwidget+=	qtermwidget>=1.1.0
BUILDLINK_ABI_DEPENDS.qtermwidget?=	qtermwidget>=1.1.0nb1
BUILDLINK_PKGSRCDIR.qtermwidget?=	../../x11/qtermwidget

#.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QTERMWIDGET_BUILDLINK3_MK

BUILDLINK_TREE+=	-qtermwidget
