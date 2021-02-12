# $NetBSD: Makefile,v 1.10 2021/02/12 08:22:00 adam Exp $

DISTNAME=	aiohttp_socks-0.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp-socks/}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/romis2012/aiohttp-socks
COMMENT=	SOCKS proxy connector for aiohttp
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-aiohttp>=2.3.2:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-attrs>=19.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-socks>=1.0.1:../../www/py-socks

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
