# $NetBSD: Makefile,v 1.2 2003/04/23 15:57:55 drochner Exp $

DISTNAME=	ZWeatherApplet-1.51
PKGNAME=	zope25-ZWeatherApplet-1.51
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/zweatherapplet/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.librelogiciel.com/software/
COMMENT=	Zope Weather applet

ZOPE_COPYPRODUCT= zope-std-copyproduct-short
USE_BUILDLINK2=	yes

.include "../../www/zope25/product.mk"
.include "../../net/py-METAR/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
