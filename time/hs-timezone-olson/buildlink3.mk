# $NetBSD: buildlink3.mk,v 1.2 2015/11/15 08:22:15 szptvlfn Exp $

BUILDLINK_TREE+=	hs-timezone-olson

.if !defined(HS_TIMEZONE_OLSON_BUILDLINK3_MK)
HS_TIMEZONE_OLSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-timezone-olson+=	hs-timezone-olson>=0.1.7
BUILDLINK_ABI_DEPENDS.hs-timezone-olson+=	hs-timezone-olson>=0.1.7
BUILDLINK_PKGSRCDIR.hs-timezone-olson?=	../../time/hs-timezone-olson

.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../time/hs-timezone-series/buildlink3.mk"
.endif	# HS_TIMEZONE_OLSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-timezone-olson
