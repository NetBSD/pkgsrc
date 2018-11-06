# $NetBSD: Makefile,v 1.8 2018/11/06 14:31:48 adam Exp $

DISTNAME=	websockets-7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/websockets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aaugustin/websockets
COMMENT=	Implementation of the WebSocket Protocol (RFC 6455)
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"

PLIST_VARS+=	py35 py36

.if !empty(_PYTHON_VERSION:M35)
PLIST.py35=		yes
.endif
.if !empty(_PYTHON_VERSION:M3[67])
PLIST.py35=		yes
PLIST.py36=		yes
.endif

.include "../../mk/bsd.pkg.mk"
