# $NetBSD: Makefile,v 1.3 2002/11/29 17:49:50 drochner Exp $

DISTNAME=	Silva-0.8.6.1
PKGNAME=	zope25-Silva-0.8.6.1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/faassen/Silva/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.infrae.com/products/silva
COMMENT=	browser based publication system

DEPENDS+=	zope25-Formulator-*:../../www/zope25-Formulator
DEPENDS+=	zope25-XMLWidgets-*:../../www/zope25-XMLWidgets
DEPENDS+=	zope25-FileSystemSite:../../www/zope25-FileSystemSite

ZOPE_COPYPRODUCT= zope-std-copyproduct-short

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
