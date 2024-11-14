# $NetBSD: buildlink3.mk,v 1.4 2024/11/14 22:22:17 wiz Exp $

BUILDLINK_TREE+=	kf6-kguiaddons

.if !defined(KF6_KGUIADDONS_BUILDLINK3_MK)
KF6_KGUIADDONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kguiaddons+=	kf6-kguiaddons>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kguiaddons?=	kf6-kguiaddons>=6.2.0nb4
BUILDLINK_PKGSRCDIR.kf6-kguiaddons?=	../../x11/kf6-kguiaddons

.include "../../devel/wayland/platform.mk"

.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
.  include "../../devel/qt6-qtwayland/buildlink3.mk"
.endif
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KGUIADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kguiaddons
