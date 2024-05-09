# $NetBSD: buildlink3.mk,v 1.11 2024/05/09 01:32:51 pho Exp $

BUILDLINK_TREE+=	hs-unix-time

.if !defined(HS_UNIX_TIME_BUILDLINK3_MK)
HS_UNIX_TIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unix-time+=	hs-unix-time>=0.4.12
BUILDLINK_ABI_DEPENDS.hs-unix-time+=	hs-unix-time>=0.4.12nb1
BUILDLINK_PKGSRCDIR.hs-unix-time?=	../../time/hs-unix-time

.include "../../time/hs-old-time/buildlink3.mk"
.endif	# HS_UNIX_TIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unix-time
