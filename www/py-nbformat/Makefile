# $NetBSD: Makefile,v 1.21 2026/08/31 12:44:49 adam Exp $

DISTNAME=	nbformat-5.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbformat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Jupyter Notebook format
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-nodejs-version>=0:../../devel/py-hatch-nodejs-version
DEPENDS+=	${PYPKGPREFIX}-fastjsonschema>=2.15:../../textproc/py-fastjsonschema
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=2.6:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.12:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.1:../../devel/py-traitlets
TEST_DEPENDS+=	${PYPKGPREFIX}-pep440>=0:../../misc/py-pep440
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath>=0:../../devel/py-testpath

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	jupyter-trust

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
