# $NetBSD: buildlink3.mk,v 1.8 2024/05/09 01:32:56 pho Exp $

BUILDLINK_TREE+=	hs-websockets

.if !defined(HS_WEBSOCKETS_BUILDLINK3_MK)
HS_WEBSOCKETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-websockets+=	hs-websockets>=0.13.0
BUILDLINK_ABI_DEPENDS.hs-websockets+=	hs-websockets>=0.13.0.0nb1
BUILDLINK_PKGSRCDIR.hs-websockets?=	../../www/hs-websockets

.include "../../devel/hs-async/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../devel/hs-bytestring-builder/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../time/hs-clock/buildlink3.mk"
.include "../../security/hs-entropy/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../security/hs-SHA/buildlink3.mk"
.include "../../devel/hs-streaming-commons/buildlink3.mk"
.endif	# HS_WEBSOCKETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-websockets
