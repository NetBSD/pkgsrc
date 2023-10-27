# $NetBSD: buildlink3.mk,v 1.17 2023/10/27 09:22:51 pho Exp $

BUILDLINK_TREE+=	xmonad

.if !defined(XMONAD_BUILDLINK3_MK)
XMONAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmonad+=	xmonad>=0.17.2
BUILDLINK_ABI_DEPENDS.xmonad+=	xmonad>=0.17.2
BUILDLINK_PKGSRCDIR.xmonad?=	../../wm/xmonad

.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../devel/hs-setlocale/buildlink3.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.endif	# XMONAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmonad
