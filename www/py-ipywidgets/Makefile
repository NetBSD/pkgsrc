# $NetBSD: Makefile,v 1.1 2019/08/21 12:41:24 adam Exp $

DISTNAME=	ipywidgets-7.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipywidgets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ipython.org/
COMMENT=	IPython HTML widgets for Jupyter
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-ipykernel>=4.5.1:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-nbformat>=4.2.0:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.3.1:../../devel/py-traitlets
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.6.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-ipykernel

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
