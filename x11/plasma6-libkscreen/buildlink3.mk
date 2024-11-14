# $NetBSD: buildlink3.mk,v 1.4 2024/11/14 22:22:24 wiz Exp $

BUILDLINK_TREE+=	plasma6-libkscreen

.if !defined(PLASMA6_LIBKSCREEN_BUILDLINK3_MK)
PLASMA6_LIBKSCREEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma6-libkscreen+=	plasma6-libkscreen>=6.0.5
BUILDLINK_ABI_DEPENDS.plasma6-libkscreen?=	plasma6-libkscreen>=6.0.5nb3
BUILDLINK_PKGSRCDIR.plasma6-libkscreen?=	../../x11/plasma6-libkscreen

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/plasma6-kwayland/buildlink3.mk"
.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# PLASMA6_LIBKSCREEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma6-libkscreen
