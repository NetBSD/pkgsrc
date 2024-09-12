# $NetBSD: Makefile,v 1.1 2024/09/12 09:18:00 wiz Exp $

DISTNAME=	aiohttp-oauthlib-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python security
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp-oauthlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~whynothugo/aiohttp-oauthlib
COMMENT=	oauthlib for aiohttp clients
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=46.4.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-aiohttp-[0-9]*:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-oauthlib-[0-9]*:../../security/py-oauthlib

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
