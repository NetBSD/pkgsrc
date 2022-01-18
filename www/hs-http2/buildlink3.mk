# $NetBSD: buildlink3.mk,v 1.2 2022/01/18 02:48:32 pho Exp $

BUILDLINK_TREE+=	hs-http2

.if !defined(HS_HTTP2_BUILDLINK3_MK)
HS_HTTP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-http2+=	hs-http2>=3.0.1
BUILDLINK_ABI_DEPENDS.hs-http2+=	hs-http2>=3.0.1nb1
BUILDLINK_PKGSRCDIR.hs-http2?=		../../www/hs-http2

.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-byte-order/buildlink3.mk"
.include "../../devel/hs-psqueues/buildlink3.mk"
.include "../../time/hs-time-manager/buildlink3.mk"
.include "../../time/hs-unix-time/buildlink3.mk"
.endif	# HS_HTTP2_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-http2
