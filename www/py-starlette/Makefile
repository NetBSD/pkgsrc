# $NetBSD: Makefile,v 1.5 2025/01/25 11:37:33 adam Exp $

DISTNAME=	starlette-0.45.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/starlette/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/encode/starlette
COMMENT=	Little ASGI library that shines
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-anyio>=3.6.2:../../devel/py-anyio
TEST_DEPENDS+=	${PYPKGPREFIX}-httpx>=0.27.0:../../www/py-httpx
TEST_DEPENDS+=	${PYPKGPREFIX}-itsdangerous-[0-9]*:../../security/py-itsdangerous
TEST_DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
TEST_DEPENDS+=	${PYPKGPREFIX}-python-multipart>=0.0.18:../../www/py-python-multipart
TEST_DEPENDS+=	${PYPKGPREFIX}-trio-[0-9]*:../../devel/py-trio
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10.0:../../devel/py-typing-extensions
.else
# TODO: shouldn't be necessary, report upstream
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10.0:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
