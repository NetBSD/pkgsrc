# $NetBSD: buildlink3.mk,v 1.10 2024/05/09 01:32:54 pho Exp $

BUILDLINK_TREE+=	hs-http-types

.if !defined(HS_HTTP_TYPES_BUILDLINK3_MK)
HS_HTTP_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-http-types+=	hs-http-types>=0.12.4
BUILDLINK_ABI_DEPENDS.hs-http-types+=	hs-http-types>=0.12.4nb1
BUILDLINK_PKGSRCDIR.hs-http-types?=	../../www/hs-http-types

.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.endif	# HS_HTTP_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-http-types
