# $NetBSD: buildlink3.mk,v 1.10 2023/11/10 17:02:28 gutteridge Exp $

BUILDLINK_TREE+=	qtermwidget

.if !defined(QTERMWIDGET_BUILDLINK3_MK)
QTERMWIDGET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qtermwidget+=	qtermwidget>=1.4.0
BUILDLINK_PKGSRCDIR.qtermwidget?=	../../x11/qtermwidget

#.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QTERMWIDGET_BUILDLINK3_MK

BUILDLINK_TREE+=	-qtermwidget
