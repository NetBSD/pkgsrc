# $NetBSD: Makefile,v 1.21 2026/08/31 12:49:44 adam Exp $

DISTNAME=	nbclient-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyter/nbclient
COMMENT=	Client library for executing notebooks
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.10.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=7.0.0:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=5.4.0:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-nbformat>=5.2.0:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.13:../../devel/py-traitlets
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=0:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-ipykernel>=6.19.3:../../devel/py-ipykernel
TEST_DEPENDS+=	${PYPKGPREFIX}-ipython>=0:../../devel/py-ipython
TEST_DEPENDS+=	${PYPKGPREFIX}-ipywidgets>=0:../../www/py-ipywidgets
TEST_DEPENDS+=	${PYPKGPREFIX}-nbconvert>=7.1.0:../../www/py-nbconvert
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=1.3.0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath>=0:../../devel/py-testpath
TEST_DEPENDS+=	${PYPKGPREFIX}-xmltodict>=0:../../textproc/py-xmltodict

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	jupyter-execute

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
