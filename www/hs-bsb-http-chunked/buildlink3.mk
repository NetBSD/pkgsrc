# $NetBSD: buildlink3.mk,v 1.12 2026/11/13 14:40:02 pho Exp $

BUILDLINK_TREE+=	hs-bsb-http-chunked

.if !defined(HS_BSB_HTTP_CHUNKED_BUILDLINK3_MK)
HS_BSB_HTTP_CHUNKED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bsb-http-chunked+=	hs-bsb-http-chunked>=0.0.0
BUILDLINK_ABI_DEPENDS.hs-bsb-http-chunked+=	hs-bsb-http-chunked>=0.0.0.4nb11
BUILDLINK_PKGSRCDIR.hs-bsb-http-chunked?=	../../www/hs-bsb-http-chunked
.endif	# HS_BSB_HTTP_CHUNKED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bsb-http-chunked
