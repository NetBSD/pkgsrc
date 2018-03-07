# $NetBSD: buildlink3.mk,v 1.4 2018/03/07 11:57:38 wiz Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	Xrandr

.if !defined(XRANDR_BUILDLINK3_MK)
XRANDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Xrandr+=	Xrandr>=0.99
BUILDLINK_ABI_DEPENDS.Xrandr+=	Xrandr>=1.0.2nb3
BUILDLINK_PKGSRCDIR.Xrandr?=	../../x11/liboldXrandr

.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.endif # XRANDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-Xrandr
