# $NetBSD: buildlink3.mk,v 1.6 2023/10/09 04:54:57 pho Exp $

BUILDLINK_TREE+=	hs-time-manager

.if !defined(HS_TIME_MANAGER_BUILDLINK3_MK)
HS_TIME_MANAGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-time-manager+=	hs-time-manager>=0.0.0
BUILDLINK_ABI_DEPENDS.hs-time-manager+=	hs-time-manager>=0.0.0nb5
BUILDLINK_PKGSRCDIR.hs-time-manager?=	../../time/hs-time-manager

.include "../../devel/hs-auto-update/buildlink3.mk"
.endif	# HS_TIME_MANAGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-time-manager
