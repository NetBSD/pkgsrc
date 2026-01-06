# $NetBSD: Makefile,v 1.7 2026/01/06 11:18:17 wiz Exp $

DISTNAME=	sphinx_basic_ng-1.0.0b2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx_basic_ng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pradyunsg/sphinx-basic-ng
COMMENT=	Modern skeleton for Sphinx themes
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sphinx>=4.0:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
