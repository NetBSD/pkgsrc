# $NetBSD: Makefile,v 1.2 2022/01/17 09:46:44 wiz Exp $

DISTNAME=	sphinx-astropy-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-astropy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astropy/sphinx-astropy
COMMENT=	Sphinx extensions and configuration specific to the Astropy project
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.7:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-astropy-sphinx-theme-[0-9]*:../../textproc/py-astropy-sphinx-theme
DEPENDS+=	${PYPKGPREFIX}-numpydoc-[0-9]*:../../textproc/py-numpydoc
DEPENDS+=	${PYPKGPREFIX}-sphinx-automodapi-[0-9]*:../../textproc/py-sphinx-automodapi
DEPENDS+=	${PYPKGPREFIX}-sphinx-gallery-[0-9]*:../../textproc/py-sphinx-gallery
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-test-doctestplus>=0.11:../../devel/py-test-doctestplus
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
