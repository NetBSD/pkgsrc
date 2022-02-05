# $NetBSD: Makefile,v 1.1 2022/02/05 11:26:35 adam Exp $

DISTNAME=	nbclient-0.5.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Client library for executing notebooks
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=6.1.5:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-nbformat>=5.0:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-nest-asyncio>0:../../devel/py-nest-asyncio
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.2:../../devel/py-traitlets
TEST_DEPENDS+=	${PYPKGPREFIX}-ipykernel>0:../../devel/py-ipykernel
TEST_DEPENDS+=	${PYPKGPREFIX}-ipython>0:../../devel/py-ipython
TEST_DEPENDS+=	${PYPKGPREFIX}-ipywidgets>0:../../www/py-ipywidgets
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-xmltodict-[0-9]*:../../textproc/py-xmltodict

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter-execute jupyter-execute-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
