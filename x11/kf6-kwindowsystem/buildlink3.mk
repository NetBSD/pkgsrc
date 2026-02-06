# $NetBSD: buildlink3.mk,v 1.11 2026/02/06 10:06:14 wiz Exp $

BUILDLINK_TREE+=	kf6-kwindowsystem

.if !defined(KF6_KWINDOWSYSTEM_BUILDLINK3_MK)
KF6_KWINDOWSYSTEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kwindowsystem+=	kf6-kwindowsystem>=6.0.0
BUILDLINK_ABI_DEPENDS.kf6-kwindowsystem?=	kf6-kwindowsystem>=6.18.0nb3
BUILDLINK_PKGSRCDIR.kf6-kwindowsystem?=		../../x11/kf6-kwindowsystem

USE_CXX_FEATURES+=	c++20

.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KWINDOWSYSTEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kwindowsystem
