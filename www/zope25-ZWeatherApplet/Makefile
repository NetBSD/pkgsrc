# $NetBSD: Makefile,v 1.6 2004/05/23 11:41:35 recht Exp $

DISTNAME=	ZWeatherApplet-1.51
PKGREVISION=	1
PKGNAME=	zope25-ZWeatherApplet-1.51
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zweatherapplet/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.librelogiciel.com/software/
COMMENT=	Zope Weather applet

DEPENDS+=	${PYPKGPREFIX}-pymetar-[0-9]*:../../net/py-METAR

ZOPE_COPYPRODUCT= zope-std-copyproduct-short
USE_BUILDLINK3=	yes

.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
