# $NetBSD: Makefile,v 1.3 2003/01/10 11:30:06 drochner Exp $

DISTNAME=	ParsedXML-1.3.1
PKGNAME=	zope25-ParsedXML-1.3.1
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
