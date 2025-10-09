# $NetBSD: Makefile,v 1.3 2025/10/09 07:58:14 wiz Exp $

DISTNAME=	websockify-0.12.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=novnc/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/novnc/websockify
COMMENT=	WebSocket to TCP proxy/bridge
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-redis-[0-9]*:../../databases/py-redis
DEPENDS+=	${PYPKGPREFIX}-jwcrypto-[0-9]*:../../www/py-jwcrypto

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
