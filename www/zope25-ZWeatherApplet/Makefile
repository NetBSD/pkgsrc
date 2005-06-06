# $NetBSD: Makefile,v 1.8 2005/06/06 00:45:49 minskim Exp $

DISTNAME=	ZWeatherApplet-1.51
PKGREVISION=	1
PKGNAME=	zope25-ZWeatherApplet-1.51
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zweatherapplet/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.librelogiciel.com/software/
COMMENT=	Zope Weather applet

BROKEN=		Dependencies (py-METAR and zope25) require different Python versions.

DEPENDS+=	${PYPKGPREFIX}-pymetar-[0-9]*:../../net/py-METAR

ZOPE_COPYPRODUCT= zope-std-copyproduct-short

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
