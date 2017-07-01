# $NetBSD: Makefile,v 1.2 2017/07/01 22:13:55 joerg Exp $

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

PLIST_VARS+=	py35p

.if empty(_PYTHON_VERSION:M34*)
PLIST.py35p=				yes
.endif

.include "../../mk/bsd.pkg.mk"
