# $NetBSD: buildlink3.mk,v 1.15 2024/11/15 12:34:40 pin Exp $

BUILDLINK_TREE+=	qtermwidget

.if !defined(QTERMWIDGET_BUILDLINK3_MK)
QTERMWIDGET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qtermwidget+=	qtermwidget>=2.1.0
BUILDLINK_PKGSRCDIR.qtermwidget?=	../../x11/qtermwidget

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QTERMWIDGET_BUILDLINK3_MK

BUILDLINK_TREE+=	-qtermwidget
