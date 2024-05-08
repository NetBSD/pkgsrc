# $NetBSD: Makefile,v 1.20 2024/05/08 15:13:36 adam Exp $

DISTNAME=	tomlkit-0.12.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tomlkit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sdispater/tomlkit
COMMENT=	Style preserving TOML library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.1:../../devel/py-poetry-core
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
