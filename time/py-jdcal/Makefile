# $NetBSD: Makefile,v 1.8 2022/01/04 20:55:12 wiz Exp $

DISTNAME=	jdcal-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jdcal/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/phn/jdcal
COMMENT=	Julian dates from proleptic Gregorian and Julian calendars
LICENSE=	modified-bsd

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} test_jdcal.py

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
