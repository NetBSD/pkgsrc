# $NetBSD: buildlink3.mk,v 1.7 2022/02/26 03:58:32 pho Exp $

BUILDLINK_TREE+=	hs-time-compat

.if !defined(HS_TIME_COMPAT_BUILDLINK3_MK)
HS_TIME_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-time-compat+=	hs-time-compat>=1.9.6
BUILDLINK_ABI_DEPENDS.hs-time-compat?=	hs-time-compat>=1.9.6.1nb2
BUILDLINK_PKGSRCDIR.hs-time-compat?=	../../time/hs-time-compat

.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.endif	# HS_TIME_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-time-compat
