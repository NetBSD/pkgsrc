# $NetBSD: buildlink3.mk,v 1.2 2022/01/18 02:48:32 pho Exp $

BUILDLINK_TREE+=	hs-warp

.if !defined(HS_WARP_BUILDLINK3_MK)
HS_WARP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-warp+=	hs-warp>=3.3.15
BUILDLINK_ABI_DEPENDS.hs-warp+=	hs-warp>=3.3.15nb1
BUILDLINK_PKGSRCDIR.hs-warp?=	../../www/hs-warp

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-auto-update/buildlink3.mk"
.include "../../www/hs-bsb-http-chunked/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../www/hs-http-date/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../www/hs-http2/buildlink3.mk"
.include "../../net/hs-iproute/buildlink3.mk"
.include "../../net/hs-simple-sendfile/buildlink3.mk"
.include "../../devel/hs-streaming-commons/buildlink3.mk"
.include "../../time/hs-time-manager/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../devel/hs-vault/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../devel/hs-word8/buildlink3.mk"
.include "../../security/hs-x509/buildlink3.mk"
.endif	# HS_WARP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-warp
