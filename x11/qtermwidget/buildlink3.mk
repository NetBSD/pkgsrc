# $NetBSD: buildlink3.mk,v 1.6 2021/11/19 09:50:40 pin Exp $

BUILDLINK_TREE+=	qtermwidget

.if !defined(QTERMWIDGET_BUILDLINK3_MK)
QTERMWIDGET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qtermwidget+=	qtermwidget>=1.0.0
BUILDLINK_PKGSRCDIR.qtermwidget?=	../../x11/qtermwidget

#.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QTERMWIDGET_BUILDLINK3_MK

BUILDLINK_TREE+=	-qtermwidget
