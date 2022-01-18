# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:31 pho Exp $

BUILDLINK_TREE+=	hs-http-types

.if !defined(HS_HTTP_TYPES_BUILDLINK3_MK)
HS_HTTP_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-http-types+=	hs-http-types>=0.12.3
BUILDLINK_ABI_DEPENDS.hs-http-types+=	hs-http-types>=0.12.3nb2
BUILDLINK_PKGSRCDIR.hs-http-types?=	../../www/hs-http-types

.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.endif	# HS_HTTP_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-http-types
