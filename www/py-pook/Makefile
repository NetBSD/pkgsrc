# $NetBSD: Makefile,v 1.1 2022/08/24 12:48:05 wiz Exp $

DISTNAME=	pook-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pook/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/h2non/pook
COMMENT=	HTTP traffic mocking and expectations made easy
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-furl>=0.5.6:../../www/py-furl
DEPENDS+=	${PYPKGPREFIX}-xmltodict>=0.11.0:../../textproc/py-xmltodict
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=2.5.1:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.6.2:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-requests>=2.20.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.24.2:../../www/py-urllib3
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0.3:../../devel/py-test

# as of 1.0.2
# 2 failed, 31 passed, 14 warnings
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
