# $NetBSD: buildlink3.mk,v 1.1 2025/03/08 03:21:46 pho Exp $

BUILDLINK_TREE+=	hs-snap-server

.if !defined(HS_SNAP_SERVER_BUILDLINK3_MK)
HS_SNAP_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-snap-server+=	hs-snap-server>=1.1.2
BUILDLINK_ABI_DEPENDS.hs-snap-server+=	hs-snap-server>=1.1.2.1
BUILDLINK_PKGSRCDIR.hs-snap-server?=	../../www/hs-snap-server

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../time/hs-clock/buildlink3.mk"
.include "../../devel/hs-io-streams/buildlink3.mk"
.include "../../net/hs-io-streams-haproxy/buildlink3.mk"
.include "../../devel/hs-lifted-base/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../www/hs-snap-core/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_SNAP_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-snap-server
