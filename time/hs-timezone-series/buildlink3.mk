# $NetBSD: buildlink3.mk,v 1.12 2024/05/09 01:32:51 pho Exp $

BUILDLINK_TREE+=	hs-timezone-series

.if !defined(HS_TIMEZONE_SERIES_BUILDLINK3_MK)
HS_TIMEZONE_SERIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-timezone-series+=	hs-timezone-series>=0.1.13
BUILDLINK_ABI_DEPENDS.hs-timezone-series+=	hs-timezone-series>=0.1.13nb6
BUILDLINK_PKGSRCDIR.hs-timezone-series?=	../../time/hs-timezone-series
.endif	# HS_TIMEZONE_SERIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-timezone-series
