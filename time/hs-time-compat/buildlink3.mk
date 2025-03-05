# $NetBSD: buildlink3.mk,v 1.15 2025/03/05 03:40:07 pho Exp $

BUILDLINK_TREE+=	hs-time-compat

.if !defined(HS_TIME_COMPAT_BUILDLINK3_MK)
HS_TIME_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-time-compat+=	hs-time-compat>=1.9.8
BUILDLINK_ABI_DEPENDS.hs-time-compat+=	hs-time-compat>=1.9.8nb2
BUILDLINK_PKGSRCDIR.hs-time-compat?=	../../time/hs-time-compat

.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_TIME_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-time-compat
