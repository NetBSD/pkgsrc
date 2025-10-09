# $NetBSD: Makefile,v 1.25 2025/10/09 07:58:04 wiz Exp $

DISTNAME=	sphinx_rtd_theme-3.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx_rtd_theme/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rtfd/sphinx_rtd_theme
COMMENT=	Sphinx readthedocs.org theme
LICENSE=	mit AND apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.19:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-sphinx>=6:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-jquery>=4:../../textproc/py-sphinxcontrib-jquery

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
