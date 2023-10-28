# $NetBSD: Makefile,v 1.16 2023/10/28 19:57:21 wiz Exp $

DISTNAME=	tomlkit-0.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tomlkit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sdispater/tomlkit
COMMENT=	Style preserving TOML library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.1:../../devel/py-poetry-core
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
