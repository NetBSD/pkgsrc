# $NetBSD: Makefile,v 1.8 2004/01/23 15:39:13 recht Exp $

DISTNAME=	ParsedXML-1.3.1
PKGREVISION=	1
PKGNAME=	zope25-ParsedXML-1.3.1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/faassen/ParsedXML/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/faassen/ParsedXML
COMMENT=	Allows you to use XML objects in the Zope environment

ZOPE_COPYPRODUCT= zope-std-copyproduct-short
USE_BUILDLINK2=	yes

.include "../../www/zope25/product.mk"
.include "../../textproc/py-xml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
