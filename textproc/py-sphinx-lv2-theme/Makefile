# $NetBSD: Makefile,v 1.7 2025/11/14 13:39:56 adam Exp $

DISTNAME=	sphinx_lv2_theme-1.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-lv2-theme/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/lv2/sphinx_lv2_theme
COMMENT=	Minimal static theme for Sphinx
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

USE_LANGUAGES=	# none
 
PYTHON_VERSIONS_INCOMPATIBLE=	310 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
