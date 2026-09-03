# $NetBSD: Makefile,v 1.23 2026/09/03 05:45:05 adam Exp $

DISTNAME=	ipywidgets-8.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipywidgets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyter-widgets/ipywidgets
COMMENT=	IPython HTML widgets for Jupyter
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-comm>=0.1.3:../../net/py-comm
DEPENDS+=	${PYPKGPREFIX}-ipython>=6.1.0:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-jupyterlab-widgets>=3.0.17:../../www/py-jupyterlab-widgets
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.3.1:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-widgetsnbextension>=4.0.16:../../www/py-widgetsnbextension
TEST_DEPENDS+=	${PYPKGPREFIX}-ipykernel>=0:../../devel/py-ipykernel
TEST_DEPENDS+=	${PYPKGPREFIX}-jsonschema>=0:../../textproc/py-jsonschema
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz>=0:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
