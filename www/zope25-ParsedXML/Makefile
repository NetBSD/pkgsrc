# $NetBSD: Makefile,v 1.2 2002/10/24 22:30:45 drochner Exp $

DISTNAME=	ParsedXML-1.3.0
PKGNAME=	zope25-ParsedXML-1.3.0
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/faassen/ParsedXML/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zope.org/Members/faassen/ParsedXML
COMMENT=	allows you to use XML objects in the Zope environment

ZOPE_COPYPRODUCT= zope-std-copyproduct-short
USE_BUILDLINK2=	yes

.include "../../www/zope25/product.mk"
.include "../../textproc/pyxml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
