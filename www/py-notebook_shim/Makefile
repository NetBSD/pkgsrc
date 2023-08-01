# $NetBSD: Makefile,v 1.2 2023/08/01 23:20:56 wiz Exp $

DISTNAME=	notebook_shim-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/notebook-shim/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/notebook_shim/
COMMENT=	For switching to Jupyter Server
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-jupyter_server>=1.8:../../www/py-jupyter_server
# TODO: import py-test_jupyter, py-test-tornasync
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-console-scripts-[0-9]*:../../devel/py-test-console-scripts
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
