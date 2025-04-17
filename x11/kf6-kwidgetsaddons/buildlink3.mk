# $NetBSD: buildlink3.mk,v 1.5 2025/04/17 21:52:59 wiz Exp $

BUILDLINK_TREE+=	kf6-kwidgetsaddons

.if !defined(KF6_KWIDGETSADDONS_BUILDLINK3_MK)
KF6_KWIDGETSADDONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kwidgetsaddons+=	kf6-kwidgetsaddons>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kwidgetsaddons?=	kf6-kwidgetsaddons>=6.8.0nb1
BUILDLINK_PKGSRCDIR.kf6-kwidgetsaddons?=	../../x11/kf6-kwidgetsaddons

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KWIDGETSADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kwidgetsaddons
