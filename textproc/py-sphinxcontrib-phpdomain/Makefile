# $NetBSD: Makefile,v 1.1 2026/03/09 03:37:17 jnemeth Exp $

DISTNAME=	sphinxcontrib_phpdomain-0.13.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-phpdomain/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sphinx-contrib/phpdomain/
COMMENT=	Extension for documenting PHP projects
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.8:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
