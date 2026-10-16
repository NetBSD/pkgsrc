# $NetBSD: Makefile,v 1.5 2026/10/16 19:06:05 adam Exp $

DISTNAME=	websockify-0.13.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=novnc/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/novnc/websockify
COMMENT=	WebSocket to TCP proxy/bridge
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-jwcrypto>=0:../../www/py-jwcrypto
DEPENDS+=	${PYPKGPREFIX}-redis>=0:../../databases/py-redis
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
