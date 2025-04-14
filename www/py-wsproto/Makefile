# $NetBSD: Makefile,v 1.11 2025/04/14 20:28:04 adam Exp $

DISTNAME=	wsproto-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wsproto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wsproto.readthedocs.io/
COMMENT=	Pure Python, pure state-machine WebSocket implementation
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-h11>=0.9.0:../../www/py-h11

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
