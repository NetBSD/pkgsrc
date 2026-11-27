# $NetBSD: Makefile,v 1.38 2026/11/27 10:30:25 adam Exp $

DISTNAME=	httpx-0.29.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/encode/httpx
COMMENT=	The next generation HTTP client
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme>=0:../../devel/py-hatch-fancy-pypi-readme
DEPENDS+=	${PYPKGPREFIX}-anyio>=0:../../devel/py-anyio
DEPENDS+=	${PYPKGPREFIX}-certifi>=0:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-httpcore>=1:../../www/py-httpcore
DEPENDS+=	${PYPKGPREFIX}-idna>=0:../../www/py-idna
# cli
DEPENDS+=	${PYPKGPREFIX}-click>=8:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-pygments>=2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-rich>=10:../../comms/py-rich
# http2
DEPENDS+=	${PYPKGPREFIX}-h2>=3:../../www/py-h2
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme>=0:../../security/py-trustme
TEST_DEPENDS+=	${PYPKGPREFIX}-uvicorn>=0:../../www/py-uvicorn

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	httpx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
