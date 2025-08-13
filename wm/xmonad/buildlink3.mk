# $NetBSD: buildlink3.mk,v 1.23 2025/08/13 11:07:40 pho Exp $

BUILDLINK_TREE+=	xmonad

.if !defined(XMONAD_BUILDLINK3_MK)
XMONAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmonad+=	xmonad>=0.18.0
BUILDLINK_ABI_DEPENDS.xmonad+=	xmonad>=0.18.0nb4
BUILDLINK_PKGSRCDIR.xmonad?=	../../wm/xmonad

.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../devel/hs-setlocale/buildlink3.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.endif	# XMONAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmonad
