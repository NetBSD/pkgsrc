# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/02/10 17:57:38 drochner Exp $

BUILDLINK_TREE+=	yelp-xsl

.if !defined(YELP_XSL_BUILDLINK3_MK)
YELP_XSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yelp-xsl+=	yelp-xsl>=3.3.1
BUILDLINK_PKGSRCDIR.yelp-xsl?=	../../textproc/yelp-xsl
.endif	# YELP_XSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-yelp-xsl
