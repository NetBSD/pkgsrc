# $NetBSD: Makefile,v 1.13 2023/05/05 03:42:13 ryoon Exp $

DISTNAME=	sphinx_rtd_theme-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx_rtd_theme/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rtfd/sphinx_rtd_theme
COMMENT=	Sphinx readthedocs.org theme
LICENSE=	modified-bsd AND ofl-v1.1

DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-jquery-[0-9]*:../../textproc/py-sphinxcontrib-jquery

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
