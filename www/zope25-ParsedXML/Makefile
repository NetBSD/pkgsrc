# $NetBSD: Makefile,v 1.5 2003/06/02 01:15:53 jschauma Exp $

DISTNAME=	ParsedXML-1.3.1
PKGREVISION=	1
PKGNAME=	zope25-ParsedXML-1.3.1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/faassen/ParsedXML/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.zope.org/Members/faassen/ParsedXML
COMMENT=	allows you to use XML objects in the Zope environment

ZOPE_COPYPRODUCT= zope-std-copyproduct-short
USE_BUILDLINK2=	yes

.include "../../www/zope25/product.mk"
.include "../../textproc/pyxml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
