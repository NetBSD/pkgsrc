# $NetBSD: buildlink3.mk,v 1.1 2020/01/15 16:55:54 pho Exp $

BUILDLINK_TREE+=	hs-cookie

.if !defined(HS_COOKIE_BUILDLINK3_MK)
HS_COOKIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cookie+=	hs-cookie>=0.4.5
BUILDLINK_ABI_DEPENDS.hs-cookie+=	hs-cookie>=0.4.5
BUILDLINK_PKGSRCDIR.hs-cookie?=		../../www/hs-cookie

.include "../../devel/hs-data-default-class/buildlink3.mk"
.endif	# HS_COOKIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cookie
