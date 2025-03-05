# $NetBSD: buildlink3.mk,v 1.15 2025/03/05 03:40:06 pho Exp $

BUILDLINK_TREE+=	hs-clock

.if !defined(HS_CLOCK_BUILDLINK3_MK)
HS_CLOCK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-clock+=	hs-clock>=0.8.4
BUILDLINK_ABI_DEPENDS.hs-clock+=	hs-clock>=0.8.4nb4
BUILDLINK_PKGSRCDIR.hs-clock?=		../../time/hs-clock
.endif	# HS_CLOCK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-clock
