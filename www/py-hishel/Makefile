# $NetBSD: Makefile,v 1.10 2026/08/11 05:47:01 adam Exp $

DISTNAME=	hishel-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hishel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/karpetrosyan/hishel
COMMENT=	Persistent cache implementation for httpx and httpcore
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-msgpack>=1.1.2:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.14.1:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
