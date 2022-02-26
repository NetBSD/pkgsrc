# $NetBSD: buildlink3.mk,v 1.5 2022/02/26 03:58:32 pho Exp $

BUILDLINK_TREE+=	hs-old-time

.if !defined(HS_OLD_TIME_BUILDLINK3_MK)
HS_OLD_TIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-old-time+=	hs-old-time>=1.1.0
BUILDLINK_ABI_DEPENDS.hs-old-time+=	hs-old-time>=1.1.0.3nb4
BUILDLINK_PKGSRCDIR.hs-old-time?=	../../time/hs-old-time

.include "../../devel/hs-old-locale/buildlink3.mk"
.endif	# HS_OLD_TIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-old-time
