# $NetBSD: Makefile,v 1.11 2025/04/14 08:49:20 adam Exp $

DISTNAME=	jdcal-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jdcal/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/phn/jdcal
COMMENT=	Julian dates from proleptic Gregorian and Julian calendars
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
