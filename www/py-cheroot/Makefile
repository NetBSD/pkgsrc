# $NetBSD: Makefile,v 1.43 2026/09/09 06:45:53 adam Exp $

DISTNAME=	cheroot-11.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/Cheroot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cheroot.cherrypy.dev/
COMMENT=	High-performance, pure-Python HTTP server used by CherryPy
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.0.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-jaraco.functools>=0:../../devel/py-jaraco.functools
DEPENDS+=	${PYPKGPREFIX}-more-itertools>=2.6:../../devel/py-more-itertools
# from dependencies/tests.in
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=6.2:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.context>=0:../../devel/py-jaraco.context
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.text>=3.1:../../textproc/py-jaraco.text
TEST_DEPENDS+=	${PYPKGPREFIX}-portend>=0:../../net/py-portend
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-unixsocket>=0:../../devel/py-requests-unixsocket
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0:../../devel/py-requests-toolbelt
TEST_DEPENDS+=	${PYPKGPREFIX}-test-clarity>=0:../../devel/py-test-clarity
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.12.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=1.11.0:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures>=0:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar>=0.9.3:../../devel/py-test-sugar
TEST_DEPENDS+=	${PYPKGPREFIX}-test-watch>=4.2.0:../../devel/py-test-watch
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.28.0:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme>=0.4.0:../../security/py-trustme

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	cheroot

PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL:test
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
