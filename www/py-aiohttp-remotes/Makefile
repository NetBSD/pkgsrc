# $NetBSD: Makefile,v 1.2 2024/08/16 19:26:51 wiz Exp $

DISTNAME=	aiohttp_remotes-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp-remotes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiohttp-remotes
COMMENT=	Library of useful tools for aiohttp.web server
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit-[0-9]*:../../devel/py-flit
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.8.1:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-test-aiohttp>=0:../../www/py-test-aiohttp
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
