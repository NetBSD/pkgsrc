# $NetBSD: buildlink3.mk,v 1.1 2024/07/21 20:42:35 markd Exp $

BUILDLINK_TREE+=	plasma6-libkscreen

.if !defined(PLASMA6_LIBKSCREEN_BUILDLINK3_MK)
PLASMA6_LIBKSCREEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma6-libkscreen+=	plasma6-libkscreen>=6.0.5
BUILDLINK_PKGSRCDIR.plasma6-libkscreen?=	../../x11/plasma6-libkscreen

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/plasma6-kwayland/buildlink3.mk"
.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# PLASMA6_LIBKSCREEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma6-libkscreen
