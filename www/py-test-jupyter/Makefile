# $NetBSD: Makefile,v 1.9 2025/12/26 12:54:33 adam Exp $

DISTNAME=	pytest_jupyter-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-jupyter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyter-server/pytest-jupyter
COMMENT=	Pytest plugin for testing Jupyter libraries and extensions
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.10.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=5.7:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-test>=7.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
