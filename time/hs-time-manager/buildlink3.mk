# $NetBSD: buildlink3.mk,v 1.13 2025/03/05 03:40:07 pho Exp $

BUILDLINK_TREE+=	hs-time-manager

.if !defined(HS_TIME_MANAGER_BUILDLINK3_MK)
HS_TIME_MANAGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-time-manager+=	hs-time-manager>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-time-manager+=	hs-time-manager>=0.2.2nb2
BUILDLINK_PKGSRCDIR.hs-time-manager?=	../../time/hs-time-manager

.include "../../devel/hs-auto-update/buildlink3.mk"
.endif	# HS_TIME_MANAGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-time-manager
