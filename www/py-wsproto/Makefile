# $NetBSD: Makefile,v 1.2 2018/02/27 06:57:26 adam Exp $

DISTNAME=	wsproto-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wsproto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wsproto.readthedocs.io/
COMMENT=	Pure Python, pure state-machine WebSocket implementation
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-h11>=0.7.0:../../www/py-h11

.include "../../lang/python/pyversion.mk"

.if "${PYPKGPREFIX}" == "py27"
DEPENDS+=	${PYPKGPREFIX}-enum34>=1.0.4:../../devel/py-enum34
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
