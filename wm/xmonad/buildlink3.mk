# $NetBSD: buildlink3.mk,v 1.5 2016/01/04 12:45:36 szptvlfn Exp $

BUILDLINK_TREE+=	xmonad

.if !defined(XMONAD_BUILDLINK3_MK)
XMONAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmonad+=	xmonad>=0.12
BUILDLINK_ABI_DEPENDS.xmonad+=	xmonad>=0.12
BUILDLINK_PKGSRCDIR.xmonad?=	../../wm/xmonad

.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-setlocale/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.endif	# XMONAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmonad
