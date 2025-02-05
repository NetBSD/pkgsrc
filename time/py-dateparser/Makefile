# $NetBSD: Makefile,v 1.17 2025/02/05 16:22:31 adam Exp $

DISTNAME=	dateparser-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dateparser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scrapinghub/dateparser
COMMENT=	Date parsing library designed to parse dates from HTML pages
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.7.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-pytz>=2024.2:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-regex>2021.8.27:../../textproc/py-regex
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=0.2:../../time/py-tzlocal
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} dateparser-download dateparser-download-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
