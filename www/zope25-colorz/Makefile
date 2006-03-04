# $NetBSD: Makefile,v 1.8 2006/03/04 21:31:06 jlam Exp $

DISTNAME=	colorz10b2
PKGREVISION=	2
PKGNAME=	zope25-colorz-1.0b2
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/maxm/productList/colorz/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/maxm/productList/colorz
COMMENT=	Color management tool

ZOPE_COPYPRODUCT= zope-std-copyproduct-short
PRODNAMES=	colorz10b2

# clean up after patch-aa
post-install:
	${RM} ${PREFIX}/lib/zope/lib/python/Products/colorz10b2/colorz.py.orig

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
