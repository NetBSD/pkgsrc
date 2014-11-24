# $NetBSD: buildlink3.mk,v 1.1 2014/11/24 21:22:37 szptvlfn Exp $

BUILDLINK_TREE+=	hs-timezone-series

.if !defined(HS_TIMEZONE_SERIES_BUILDLINK3_MK)
HS_TIMEZONE_SERIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-timezone-series+=	hs-timezone-series>=0.1.3
BUILDLINK_ABI_DEPENDS.hs-timezone-series+=	hs-timezone-series>=0.1.3
BUILDLINK_PKGSRCDIR.hs-timezone-series?=	../../time/hs-timezone-series
.endif	# HS_TIMEZONE_SERIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-timezone-series
