# $NetBSD: Makefile,v 1.1.1.1 2002/09/12 18:16:51 drochner Exp $

DISTNAME=	Silva-0.8.3
PKGNAME=	zope25-Silva-0.8.3
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/faassen/Silva/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.infrae.com/products/silva
COMMENT=	browser based publication system

DEPENDS+=	zope25-Formulator-*:../../www/zope25-Formulator
DEPENDS+=	zope25-XMLWidgets-*:../../www/zope25-XMLWidgets

ZOPE_COPYPRODUCT= zope-std-copyproduct-short

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
