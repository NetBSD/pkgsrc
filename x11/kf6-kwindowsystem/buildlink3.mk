# $NetBSD: buildlink3.mk,v 1.5 2025/01/31 11:52:21 wiz Exp $

BUILDLINK_TREE+=	kf6-kwindowsystem

.if !defined(KF6_KWINDOWSYSTEM_BUILDLINK3_MK)
KF6_KWINDOWSYSTEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kwindowsystem+=	kf6-kwindowsystem>=6.0.0
BUILDLINK_ABI_DEPENDS.kf6-kwindowsystem?=	kf6-kwindowsystem>=6.2.0nb4
BUILDLINK_PKGSRCDIR.kf6-kwindowsystem?=		../../x11/kf6-kwindowsystem

.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KWINDOWSYSTEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kwindowsystem
