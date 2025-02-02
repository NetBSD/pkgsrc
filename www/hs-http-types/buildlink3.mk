# $NetBSD: buildlink3.mk,v 1.11 2025/02/02 13:06:04 pho Exp $

BUILDLINK_TREE+=	hs-http-types

.if !defined(HS_HTTP_TYPES_BUILDLINK3_MK)
HS_HTTP_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-http-types+=	hs-http-types>=0.12.4
BUILDLINK_ABI_DEPENDS.hs-http-types+=	hs-http-types>=0.12.4nb2
BUILDLINK_PKGSRCDIR.hs-http-types?=	../../www/hs-http-types

.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.endif	# HS_HTTP_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-http-types
