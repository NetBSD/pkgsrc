# $NetBSD: Makefile,v 1.33 2026/01/11 09:57:53 adam Exp $

DISTNAME=	websockets-16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/websockets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aaugustin/websockets
COMMENT=	Implementation of the WebSocket Protocol (RFC 6455)
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

# even after 'make install', testing doesn't work at all
# 9 errors

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} websockets websockets-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
