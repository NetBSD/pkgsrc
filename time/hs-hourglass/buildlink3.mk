# $NetBSD: buildlink3.mk,v 1.1 2020/01/16 23:27:03 pho Exp $

BUILDLINK_TREE+=	hs-hourglass

.if !defined(HS_HOURGLASS_BUILDLINK3_MK)
HS_HOURGLASS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hourglass+=	hs-hourglass>=0.2.12
BUILDLINK_ABI_DEPENDS.hs-hourglass+=	hs-hourglass>=0.2.12
BUILDLINK_PKGSRCDIR.hs-hourglass?=	../../time/hs-hourglass
.endif	# HS_HOURGLASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hourglass
