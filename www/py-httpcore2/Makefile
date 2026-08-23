# $NetBSD: Makefile,v 1.5 2026/08/23 08:08:50 wiz Exp $

DISTNAME=	httpcore2-2.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpcore2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydantic/httpx2
COMMENT=	Minimal low-level HTTP client
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme>=0:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-dynamic-versioning>=0.8.0:../../devel/py-uv-dynamic-versioning
DEPENDS+=	${PYPKGPREFIX}-truststore>=0.10:../../security/py-truststore
DEPENDS+=	${PYPKGPREFIX}-h11>=0.16:../../www/py-h11
# optional
DEPENDS+=	${PYPKGPREFIX}-anyio>=4.5.0:../../devel/py-anyio
DEPENDS+=	${PYPKGPREFIX}-h2>=3:../../www/py-h2
DEPENDS+=	${PYPKGPREFIX}-trio>=0.22.0:../../devel/py-trio
# TODO: package socksio-1

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
