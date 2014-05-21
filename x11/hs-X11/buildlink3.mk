# $NetBSD: buildlink3.mk,v 1.1 2014/05/21 20:55:51 szptvlfn Exp $

BUILDLINK_TREE+=	hs-X11

.if !defined(HS_X11_BUILDLINK3_MK)
HS_X11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-X11+=	hs-X11>=1.6.1
BUILDLINK_PKGSRCDIR.hs-X11?=	../../x11/hs-X11

.include "../../devel/hs-data-default/buildlink3.mk"
.endif	# HS_X11_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-X11
