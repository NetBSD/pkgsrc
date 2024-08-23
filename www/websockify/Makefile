# $NetBSD: Makefile,v 1.1 2024/08/23 09:59:22 nia Exp $

DISTNAME=	websockify-0.12.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=novnc/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/novnc/websockify
COMMENT=	WebSocket to TCP proxy/bridge
LICENSE=	gnu-lgpl-v3

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-redis-[0-9]*:../../databases/py-redis
DEPENDS+=	${PYPKGPREFIX}-jwcrypto-[0-9]*:../../www/py-jwcrypto

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
