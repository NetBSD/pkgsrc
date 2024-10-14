# $NetBSD: Makefile,v 1.6 2024/10/14 06:46:01 wiz Exp $

DISTNAME=	sphinx-astropy-1.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-astropy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astropy/sphinx-astropy
COMMENT=	Sphinx extensions and configuration specific to the Astropy project
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=30.3.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-astropy-sphinx-theme-[0-9]*:../../textproc/py-astropy-sphinx-theme
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-numpydoc-[0-9]*:../../textproc/py-numpydoc
DEPENDS+=	${PYPKGPREFIX}-sphinx>=3.0.0:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-sphinx-automodapi-[0-9]*:../../textproc/py-sphinx-automodapi
DEPENDS+=	${PYPKGPREFIX}-sphinx-gallery-[0-9]*:../../textproc/py-sphinx-gallery
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-jquery-[0-9]*:../../textproc/py-sphinxcontrib-jquery
DEPENDS+=	${PYPKGPREFIX}-test-doctestplus>=0.11:../../devel/py-test-doctestplus

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
