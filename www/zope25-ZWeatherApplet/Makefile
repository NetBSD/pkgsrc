# $NetBSD: Makefile,v 1.4 2003/06/02 01:15:50 jschauma Exp $

DISTNAME=	ZWeatherApplet-1.51
PKGREVISION=	1
PKGNAME=	zope25-ZWeatherApplet-1.51
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/zweatherapplet/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.librelogiciel.com/software/
COMMENT=	Zope Weather applet

ZOPE_COPYPRODUCT= zope-std-copyproduct-short
USE_BUILDLINK2=	yes

.include "../../www/zope25/product.mk"
.include "../../net/py-METAR/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
