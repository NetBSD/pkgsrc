# $NetBSD: buildlink3.mk,v 1.2 2024/05/09 01:32:53 pho Exp $

BUILDLINK_TREE+=	hs-http-semantics

.if !defined(HS_HTTP_SEMANTICS_BUILDLINK3_MK)
HS_HTTP_SEMANTICS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-http-semantics+=	hs-http-semantics>=0.0.0
BUILDLINK_ABI_DEPENDS.hs-http-semantics+=	hs-http-semantics>=0.0.0nb1
BUILDLINK_PKGSRCDIR.hs-http-semantics?=		../../www/hs-http-semantics

.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-byte-order/buildlink3.mk"
.include "../../time/hs-time-manager/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.endif	# HS_HTTP_SEMANTICS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-http-semantics
