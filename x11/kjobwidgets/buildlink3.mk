# $NetBSD: buildlink3.mk,v 1.18 2020/06/02 08:23:04 adam Exp $

BUILDLINK_TREE+=	kjobwidgets

.if !defined(KJOBWIDGETS_BUILDLINK3_MK)
KJOBWIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kjobwidgets+=	kjobwidgets>=5.19.0
BUILDLINK_ABI_DEPENDS.kjobwidgets?=	kjobwidgets>=5.66.0nb4
BUILDLINK_PKGSRCDIR.kjobwidgets?=	../../x11/kjobwidgets

.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif	# KJOBWIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kjobwidgets
