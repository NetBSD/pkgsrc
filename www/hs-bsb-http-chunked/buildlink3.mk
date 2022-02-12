# $NetBSD: buildlink3.mk,v 1.3 2022/02/12 08:50:58 pho Exp $

BUILDLINK_TREE+=	hs-bsb-http-chunked

.if !defined(HS_BSB_HTTP_CHUNKED_BUILDLINK3_MK)
HS_BSB_HTTP_CHUNKED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bsb-http-chunked+=	hs-bsb-http-chunked>=0.0.0
BUILDLINK_ABI_DEPENDS.hs-bsb-http-chunked+=	hs-bsb-http-chunked>=0.0.0.4nb2
BUILDLINK_PKGSRCDIR.hs-bsb-http-chunked?=	../../www/hs-bsb-http-chunked
.endif	# HS_BSB_HTTP_CHUNKED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bsb-http-chunked
