# $NetBSD: buildlink3.mk,v 1.25 2022/08/11 05:09:28 gutteridge Exp $

BUILDLINK_TREE+=	kguiaddons

.if !defined(KGUIADDONS_BUILDLINK3_MK)
KGUIADDONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kguiaddons+=	kguiaddons>=5.18.0
BUILDLINK_ABI_DEPENDS.kguiaddons?=	kguiaddons>=5.93.0nb1
BUILDLINK_PKGSRCDIR.kguiaddons?=	../../x11/kguiaddons

.include "../../devel/wayland/platform.mk"

.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
.  include "../../x11/qt5-qtwayland/buildlink3.mk"
.endif

.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif	# KGUIADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kguiaddons
