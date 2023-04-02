# $NetBSD: Makefile,v 1.13 2023/04/02 18:58:27 adam Exp $

DISTNAME=	tomlkit-0.11.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tomlkit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sdispater/tomlkit
COMMENT=	Style preserving TOML library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.1:../../devel/py-poetry-core
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml>=5.0:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
