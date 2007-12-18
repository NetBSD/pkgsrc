# $NetBSD: product.mk,v 1.1.1.1 2007/12/18 15:37:49 taca Exp $
#

.if !defined(_PLONE_PRODUCT_MK)
_PLONE_PRODUCT_MK=	# defined

.include "../../www/plone/ploneversion.mk"

DEPENDS+=	${PLONE_DEPENDENCY}

.endif
