# $NetBSD: Makefile,v 1.11 2004/10/03 00:18:27 tv Exp $

DISTNAME=	ParsedXML-1.3.1
PKGREVISION=	3
PKGNAME=	zope25-ParsedXML-1.3.1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/faassen/ParsedXML/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/faassen/ParsedXML
COMMENT=	Allows you to use XML objects in the Zope environment

ZOPE_COPYPRODUCT= zope-std-copyproduct-short
USE_BUILDLINK3=	yes

.include "../../www/zope25/product.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
