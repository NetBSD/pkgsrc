# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:36 rillig Exp $

BUILDLINK_TREE+=	yelp-xsl

.if !defined(YELP_XSL_BUILDLINK3_MK)
YELP_XSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yelp-xsl+=	yelp-xsl>=3.3.1
BUILDLINK_PKGSRCDIR.yelp-xsl?=		../../textproc/yelp-xsl
.endif	# YELP_XSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-yelp-xsl
