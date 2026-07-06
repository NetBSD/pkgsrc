# $NetBSD: Makefile,v 1.1 2026/07/06 06:54:46 wiz Exp $

DISTNAME=	httpx2-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpx2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydantic/httpx2
COMMENT=	Next generation HTTP client
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme-[0-9]*:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-dynamic-versioning-[0-9]*:../../devel/py-uv-dynamic-versioning
DEPENDS+=	${PYPKGPREFIX}-truststore>=0.10:../../security/py-truststore
DEPENDS+=	${PYPKGPREFIX}-httpcore2>=${PKGVERSION_NOREV}:../../www/py-httpcore2
DEPENDS+=	${PYPKGPREFIX}-anyio-[0-9]*:../../devel/py-anyio
DEPENDS+=	${PYPKGPREFIX}-idna>=3.18:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-brotli-[0-9]*:../../archivers/py-brotli
DEPENDS+=	${PYPKGPREFIX}-click>=8:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-pygments>=2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-rich>=10:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-h2>=3:../../www/py-h2
# TODO: wants socksio-1*

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 313
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.5.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-zstandard>=0.18.0:../../archivers/py-zstandard
.endif

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	httpx2

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
