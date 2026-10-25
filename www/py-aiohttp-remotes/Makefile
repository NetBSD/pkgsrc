# $NetBSD: Makefile,v 1.9 2026/10/25 15:52:15 wiz Exp $

DISTNAME=	aiohttp_remotes-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp-remotes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiohttp-remotes
COMMENT=	Library of useful tools for aiohttp.web server
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
TOOL_DEPENDS+=	${PYPKGPREFIX}-flit-[0-9]*:../../devel/py-flit
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.8.1:../../www/py-aiohttp

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
