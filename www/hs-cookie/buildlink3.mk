# $NetBSD: buildlink3.mk,v 1.5 2022/02/26 03:58:34 pho Exp $

BUILDLINK_TREE+=	hs-cookie

.if !defined(HS_COOKIE_BUILDLINK3_MK)
HS_COOKIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cookie+=	hs-cookie>=0.4.5
BUILDLINK_ABI_DEPENDS.hs-cookie+=	hs-cookie>=0.4.5nb4
BUILDLINK_PKGSRCDIR.hs-cookie?=		../../www/hs-cookie

.include "../../devel/hs-data-default-class/buildlink3.mk"
.endif	# HS_COOKIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cookie
