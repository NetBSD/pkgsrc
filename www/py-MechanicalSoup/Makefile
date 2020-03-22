# $NetBSD: Makefile,v 1.7 2020/03/22 12:28:28 rillig Exp $

DISTNAME=	MechanicalSoup-0.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/MechanicalSoup/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hickford/MechanicalSoup
COMMENT=	Library for automating interaction with websites
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.4:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.4:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock-[0-9]*:../../devel/py-requests-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpbin-[0-9]*:../../www/py-test-httpbin
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYPKGPREFIX} == py27
TEST_DEPENDS=	# none; py-test-httpbin is incompatible with py27
do-test:
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
