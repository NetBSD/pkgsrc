# $NetBSD: Makefile,v 1.10 2024/11/11 07:29:30 wiz Exp $

DISTNAME=	wsproto-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wsproto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wsproto.readthedocs.io/
COMMENT=	Pure Python, pure state-machine WebSocket implementation
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-h11>=0.9.0:../../www/py-h11

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
