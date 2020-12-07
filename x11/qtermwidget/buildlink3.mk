# $NetBSD: buildlink3.mk,v 1.3 2020/12/07 11:48:54 pin Exp $

BUILDLINK_TREE+=	qtermwidget

.if !defined(QTERMWIDGET_BUILDLINK3_MK)
QTERMWIDGET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qtermwidget+=	qtermwidget>=0.16.1
BUILDLINK_PKGSRCDIR.qtermwidget?=	../../x11/qtermwidget

#.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QTERMWIDGET_BUILDLINK3_MK

BUILDLINK_TREE+=	-qtermwidget
