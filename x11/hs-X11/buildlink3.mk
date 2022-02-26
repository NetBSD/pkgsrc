# $NetBSD: buildlink3.mk,v 1.13 2022/02/26 03:58:36 pho Exp $

BUILDLINK_TREE+=	hs-X11

.if !defined(HS_X11_BUILDLINK3_MK)
HS_X11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-X11+=	hs-X11>=1.10.2
BUILDLINK_ABI_DEPENDS.hs-X11+=	hs-X11>=1.10.2nb2
BUILDLINK_PKGSRCDIR.hs-X11?=	../../x11/hs-X11

.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.endif	# HS_X11_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-X11
