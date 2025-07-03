# $NetBSD: Makefile,v 1.2 2025/07/03 19:18:12 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
