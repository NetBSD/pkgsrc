# $NetBSD: buildlink3.mk,v 1.10 2025/03/05 03:40:08 pho Exp $

BUILDLINK_TREE+=	hs-bsb-http-chunked

.if !defined(HS_BSB_HTTP_CHUNKED_BUILDLINK3_MK)
HS_BSB_HTTP_CHUNKED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bsb-http-chunked+=	hs-bsb-http-chunked>=0.0.0
BUILDLINK_ABI_DEPENDS.hs-bsb-http-chunked+=	hs-bsb-http-chunked>=0.0.0.4nb9
BUILDLINK_PKGSRCDIR.hs-bsb-http-chunked?=	../../www/hs-bsb-http-chunked
.endif	# HS_BSB_HTTP_CHUNKED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bsb-http-chunked
