# $NetBSD: Makefile,v 1.1 2017/06/24 07:30:18 adam Exp $

DISTNAME=	websockets-3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/websockets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aaugustin/websockets
COMMENT=	Implementation of the WebSocket Protocol (RFC 6455)
LICENSE=	modified-bsd

PYTHON_VERSIONS_ACCEPTED=	36 35 34

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
