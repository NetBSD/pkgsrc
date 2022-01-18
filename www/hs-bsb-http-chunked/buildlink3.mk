# $NetBSD: buildlink3.mk,v 1.2 2022/01/18 02:48:31 pho Exp $

BUILDLINK_TREE+=	hs-bsb-http-chunked

.if !defined(HS_BSB_HTTP_CHUNKED_BUILDLINK3_MK)
HS_BSB_HTTP_CHUNKED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bsb-http-chunked+=	hs-bsb-http-chunked>=0.0.0
BUILDLINK_ABI_DEPENDS.hs-bsb-http-chunked+=	hs-bsb-http-chunked>=0.0.0.4nb1
BUILDLINK_PKGSRCDIR.hs-bsb-http-chunked?=	../../www/hs-bsb-http-chunked
.endif	# HS_BSB_HTTP_CHUNKED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bsb-http-chunked
