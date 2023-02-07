# $NetBSD: buildlink3.mk,v 1.9 2023/02/07 01:41:16 pho Exp $

BUILDLINK_TREE+=	hs-clock

.if !defined(HS_CLOCK_BUILDLINK3_MK)
HS_CLOCK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-clock+=	hs-clock>=0.8.3
BUILDLINK_ABI_DEPENDS.hs-clock+=	hs-clock>=0.8.3nb2
BUILDLINK_PKGSRCDIR.hs-clock?=		../../time/hs-clock
.endif	# HS_CLOCK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-clock
