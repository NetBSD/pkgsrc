# $NetBSD: Makefile,v 1.6 2019/05/05 04:59:38 adam Exp $

DISTNAME=	jdcal-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jdcal/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/phn/jdcal
COMMENT=	Julian dates from proleptic Gregorian and Julian calendars
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} test_jdcal.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
