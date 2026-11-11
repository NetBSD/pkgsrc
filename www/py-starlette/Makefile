# $NetBSD: Makefile,v 1.20 2026/11/11 14:03:18 wiz Exp $

DISTNAME=	starlette-1.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/starlette/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/encode/starlette
COMMENT=	Little ASGI library that shines
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-anyio>=4.0.0:../../devel/py-anyio
DEPENDS+=	${PYPKGPREFIX}-httpx2>=2.0.0:../../www/py-httpx2
TEST_DEPENDS+=	${PYPKGPREFIX}-httpx>=0.27.0:../../www/py-httpx
TEST_DEPENDS+=	${PYPKGPREFIX}-itsdangerous>=0:../../security/py-itsdangerous
TEST_DEPENDS+=	${PYPKGPREFIX}-jinja2>=0:../../textproc/py-jinja2
TEST_DEPENDS+=	${PYPKGPREFIX}-opentelemetry-api>=0:../../devel/py-opentelemetry-api
TEST_DEPENDS+=	${PYPKGPREFIX}-python-multipart>=0.0.18:../../www/py-python-multipart
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml>=0:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-trio>=0.34.0:../../devel/py-trio

USE_LANGUAGES=	# none

# as of 1.10.0nb1
# 1357 passed, 2 skipped, 2 xfailed

# E   ModuleNotFoundError: No module named 'opentelemetry.sdk'. Did you mean: 'opentelemetry.util'?
pre-test:
	${RM} -f ${WRKSRC}/tests/middleware/test_opentelemetry.py

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 313
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.10.0:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
