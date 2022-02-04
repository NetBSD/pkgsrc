# $NetBSD: Makefile,v 1.9 2022/02/04 13:49:26 adam Exp $

DISTNAME=	ipywidgets-7.6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipywidgets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ipython.org/
COMMENT=	IPython HTML widgets for Jupyter
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-ipykernel>=4.5.1:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-ipython_genutils>=0.2.0:../../devel/py-ipython_genutils
DEPENDS+=	${PYPKGPREFIX}-nbformat>=4.2.0:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.3.1:../../devel/py-traitlets
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.6.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
