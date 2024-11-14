# $NetBSD: buildlink3.mk,v 1.4 2024/11/14 22:21:58 wiz Exp $

BUILDLINK_TREE+=	kf6-kcalendarcore

.if !defined(KF6_KCALENDARCORE_BUILDLINK3_MK)
KF6_KCALENDARCORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kcalendarcore+=	kf6-kcalendarcore>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kcalendarcore?=		kf6-kcalendarcore>=6.2.0nb4
BUILDLINK_PKGSRCDIR.kf6-kcalendarcore?=		../../time/kf6-kcalendarcore

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KCALENDARCORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kcalendarcore
