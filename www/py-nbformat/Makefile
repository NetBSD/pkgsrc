# $NetBSD: Makefile,v 1.18 2023/10/28 19:57:24 wiz Exp $

DISTNAME=	nbformat-5.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbformat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Jupyter Notebook format
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-nodejs-version-[0-9]*:../../devel/py-hatch-nodejs-version
DEPENDS+=	${PYPKGPREFIX}-fastjsonschema-[0-9]*:../../textproc/py-fastjsonschema
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=2.6:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-jupyter_core-[0-9]*:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.1:../../devel/py-traitlets
TEST_DEPENDS+=	${PYPKGPREFIX}-pep440-[0-9]*:../../misc/py-pep440
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath-[0-9]*:../../devel/py-testpath

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter-trust jupyter-trust-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
