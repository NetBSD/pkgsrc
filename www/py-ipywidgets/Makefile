# $NetBSD: Makefile,v 1.13 2024/02/12 19:09:02 adam Exp $

DISTNAME=	ipywidgets-8.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipywidgets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyter-widgets/ipywidgets
COMMENT=	IPython HTML widgets for Jupyter
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=40.8.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-comm>=0.1.3:../../net/py-comm
DEPENDS+=	${PYPKGPREFIX}-ipython>=6.1.0:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-jupyterlab-widgets>=3.0.10:../../www/py-jupyterlab-widgets
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.3.1:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-widgetsnbextension>=4.0.10:../../www/py-widgetsnbextension
TEST_DEPENDS+=	${PYPKGPREFIX}-ipykernel-[0-9]*:../../devel/py-ipykernel
TEST_DEPENDS+=	${PYPKGPREFIX}-jsonschema-[0-9]*:../../textproc/py-jsonschema
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
