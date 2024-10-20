# $NetBSD: buildlink3.mk,v 1.2 2024/10/20 14:04:51 wiz Exp $

BUILDLINK_TREE+=	kf6-kjobwidgets

.if !defined(KF6_KJOBWIDGETS_BUILDLINK3_MK)
KF6_KJOBWIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kjobwidgets+=	kf6-kjobwidgets>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kjobwidgets?=	kf6-kjobwidgets>=6.2.0nb2
BUILDLINK_PKGSRCDIR.kf6-kjobwidgets?=	../../x11/kf6-kjobwidgets

.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KJOBWIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kjobwidgets
