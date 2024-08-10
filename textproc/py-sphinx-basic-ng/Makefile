# $NetBSD: Makefile,v 1.3 2024/08/10 08:06:56 adam Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	27 38 39 # py-sphinx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
