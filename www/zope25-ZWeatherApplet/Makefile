# $NetBSD: Makefile,v 1.1.1.1 2002/12/03 19:36:49 drochner Exp $

DISTNAME=	ZWeatherApplet-1.50
PKGNAME=	zope25-ZWeatherApplet-1.50
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/zweatherapplet/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.librelogiciel.com/software/
COMMENT=	Zope Weather applet

ZOPE_COPYPRODUCT= ZWeatherApplet-copyproduct
USE_BUILDLINK2=	yes

ZWeatherApplet-copyproduct:
	${CP} -r ${WRKSRC}/ZWeatherApplet-1.50 \
		${ZOPEDIR}/lib/python/Products/ZWeatherApplet

.include "../../www/zope25/product.mk"
.include "../../net/py-METAR/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
