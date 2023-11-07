# $NetBSD: Makefile,v 1.2 2023/11/07 22:38:05 wiz Exp $

DISTNAME=	sphinx_basic_ng-1.0.0b2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx_basic_ng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pradyunsg/sphinx-basic-ng
COMMENT=	Modern skeleton for Sphinx themes
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-sphinx>=4.0:../../textproc/py-sphinx

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
