# $NetBSD: Makefile,v 1.8 2003/07/22 04:14:45 martti Exp $

DISTNAME=	Silva-0.8.6.1
PKGREVISION=	1
PKGNAME=	zope25-Silva-0.8.6.1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/faassen/Silva/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.infrae.com/products/silva
COMMENT=	Browser based publication system

DEPENDS+=	zope25-Formulator-[0-9]*:../../www/zope25-Formulator
DEPENDS+=	zope25-XMLWidgets-[0-9]*:../../www/zope25-XMLWidgets
DEPENDS+=	zope25-FileSystemSite-[0-9]*:../../www/zope25-FileSystemSite

ZOPE_COPYPRODUCT= zope-std-copyproduct-short

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
