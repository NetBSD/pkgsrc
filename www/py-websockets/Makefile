# $NetBSD: Makefile,v 1.3 2017/08/22 08:47:50 adam Exp $

DISTNAME=	websockets-3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/websockets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aaugustin/websockets
COMMENT=	Implementation of the WebSocket Protocol (RFC 6455)
LICENSE=	modified-bsd

PYTHON_VERSIONS_ACCEPTED=	36 35 34

.include "../../lang/python/egg.mk"

PLIST_VARS+=	py35p

.if empty(_PYTHON_VERSION:M34*)
PLIST.py35p=				yes
.endif

.include "../../mk/bsd.pkg.mk"
