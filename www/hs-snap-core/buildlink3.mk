# $NetBSD: buildlink3.mk,v 1.1 2025/03/08 02:59:26 pho Exp $

BUILDLINK_TREE+=	hs-snap-core

.if !defined(HS_SNAP_CORE_BUILDLINK3_MK)
HS_SNAP_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-snap-core+=	hs-snap-core>=1.0.5
BUILDLINK_ABI_DEPENDS.hs-snap-core+=	hs-snap-core>=1.0.5.1
BUILDLINK_PKGSRCDIR.hs-snap-core?=	../../www/hs-snap-core

.include "../../devel/hs-HUnit/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-bytestring-builder/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-lifted-base/buildlink3.mk"
.include "../../devel/hs-io-streams/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-readable/buildlink3.mk"
.include "../../textproc/hs-regex-posix/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.endif	# HS_SNAP_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-snap-core
