# $NetBSD: Makefile,v 1.8 2022/08/08 07:23:51 adam Exp $

DISTNAME=	tomlkit-0.11.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tomlkit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sdispater/tomlkit
COMMENT=	Style preserving TOML library
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml>=5.0:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
