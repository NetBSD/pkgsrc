# $NetBSD: Makefile,v 1.3 2025/04/13 20:39:35 wiz Exp $

DISTNAME=	aiohttp-oauthlib-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python security
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp-oauthlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~whynothugo/aiohttp-oauthlib
COMMENT=	oauthlib for aiohttp clients
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-aiohttp-[0-9]*:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-oauthlib-[0-9]*:../../security/py-oauthlib

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
