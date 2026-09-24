# $NetBSD: Makefile,v 1.6 2026/09/24 09:51:39 adam Exp $

DISTNAME=	httpx2-2.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpx2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydantic/httpx2
COMMENT=	Next generation HTTP client
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme>=0:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-dynamic-versioning>=0.14.1:../../devel/py-uv-dynamic-versioning
DEPENDS+=	${PYPKGPREFIX}-anyio>=4.10:../../devel/py-anyio
DEPENDS+=	${PYPKGPREFIX}-httpcore2>=${PKGVERSION_NOREV}:../../www/py-httpcore2
DEPENDS+=	${PYPKGPREFIX}-idna>=3.18:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-truststore>=0.10:../../security/py-truststore

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 313
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.5.0:../../devel/py-typing-extensions
.endif

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	httpx2

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
