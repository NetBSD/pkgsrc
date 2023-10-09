# $NetBSD: buildlink3.mk,v 1.7 2023/10/09 04:54:56 pho Exp $

BUILDLINK_TREE+=	hs-hourglass

.if !defined(HS_HOURGLASS_BUILDLINK3_MK)
HS_HOURGLASS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hourglass+=	hs-hourglass>=0.2.12
BUILDLINK_ABI_DEPENDS.hs-hourglass+=	hs-hourglass>=0.2.12nb6
BUILDLINK_PKGSRCDIR.hs-hourglass?=	../../time/hs-hourglass
.endif	# HS_HOURGLASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hourglass
