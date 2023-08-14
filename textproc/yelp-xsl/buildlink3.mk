# $NetBSD: buildlink3.mk,v 1.3 2023/08/14 05:25:26 wiz Exp $

BUILDLINK_TREE+=	yelp-xsl

.if !defined(YELP_XSL_BUILDLINK3_MK)
YELP_XSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yelp-xsl+=	yelp-xsl>=3.3.1
BUILDLINK_ABI_DEPENDS.yelp-xsl?=		yelp-xsl>=3.32.1nb2
BUILDLINK_PKGSRCDIR.yelp-xsl?=		../../textproc/yelp-xsl
.endif	# YELP_XSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-yelp-xsl
