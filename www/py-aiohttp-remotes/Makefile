# $NetBSD: Makefile,v 1.7 2026/08/12 22:16:28 wiz Exp $

DISTNAME=	aiohttp_remotes-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp-remotes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiohttp-remotes
COMMENT=	Library of useful tools for aiohttp.web server
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
TOOL_DEPENDS+=	${PYPKGPREFIX}-flit-[0-9]*:../../devel/py-flit
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.8.1:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-test-aiohttp>=0:../../www/py-test-aiohttp
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

# https://github.com/aio-libs/aiohttp-remotes/issues/621
BROKEN=		"Needs fixing for flit_core 4."

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
