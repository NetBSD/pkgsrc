# $NetBSD: Makefile,v 1.1.1.1 2002/09/12 18:14:02 drochner Exp $

DISTNAME=	XMLWidgets-0.8.1
PKGNAME=	zope25-XMLWidgets-0.8.1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/faassen/XMLWidgets/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zope.org/Members/faassen/XMLWidgets
COMMENT=	dynamic translations of ParsedXML documents to HTML

DEPENDS+=	zope25-ParsedXML-*:../../www/zope25-ParsedXML

ZOPE_COPYPRODUCT= zope-std-copyproduct-short

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
