# $NetBSD: Makefile,v 1.24 2026/10/16 19:44:18 adam Exp $

DISTNAME=	pallets_sphinx_themes-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pallets-Sphinx-Themes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pallets/pallets-sphinx-themes
COMMENT=	Sphinx themes for Pallets and related projects
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-sphinx>=7.3:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-sphinx-notfound-page-[0-9]*:../../textproc/py-sphinx-notfound-page

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
