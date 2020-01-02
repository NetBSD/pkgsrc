# $NetBSD: buildlink3.mk,v 1.5 2020/01/02 16:48:30 pho Exp $

BUILDLINK_TREE+=	hs-X11

.if !defined(HS_X11_BUILDLINK3_MK)
HS_X11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-X11+=	hs-X11>=1.9.1
BUILDLINK_ABI_DEPENDS.hs-X11+=	hs-X11>=1.9.1
BUILDLINK_PKGSRCDIR.hs-X11?=	../../x11/hs-X11

.include "../../devel/hs-data-default/buildlink3.mk"
.endif	# HS_X11_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-X11
