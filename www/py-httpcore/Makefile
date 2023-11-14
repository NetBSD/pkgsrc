# $NetBSD: Makefile,v 1.31 2023/11/14 17:54:38 adam Exp $

DISTNAME=	httpcore-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpcore/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/encode/httpcore
COMMENT=	Minimal low-level HTTP client
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme-[0-9]*:../../devel/py-hatch-fancy-pypi-readme
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-h11>=0.13:../../www/py-h11
# asyncio
DEPENDS+=	${PYPKGPREFIX}-anyio>=4.0:../../devel/py-anyio
# http2
DEPENDS+=	${PYPKGPREFIX}-h2>=3.0:../../www/py-h2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
