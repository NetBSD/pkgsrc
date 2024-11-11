# $NetBSD: Makefile,v 1.10 2024/11/11 07:29:12 wiz Exp $

DISTNAME=	jdcal-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jdcal/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/phn/jdcal
COMMENT=	Julian dates from proleptic Gregorian and Julian calendars
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
