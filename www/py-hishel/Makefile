# $NetBSD: Makefile,v 1.8 2026/05/11 16:13:44 adam Exp $

DISTNAME=	hishel-1.2.1
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
