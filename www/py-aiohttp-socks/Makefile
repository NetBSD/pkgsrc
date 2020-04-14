# $NetBSD: Makefile,v 1.1 2020/04/14 19:52:15 js Exp $

DISTNAME=	aiohttp_socks-0.2.2
PKGNAME=	${PYPKGPREFIX}-aiohttp-socks-0.2.2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp-socks/}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/romis2012/aiohttp-socks
COMMENT=	SOCKS proxy connector for aiohttp
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-aiohttp>=2.3.2:../../www/py-aiohttp

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
