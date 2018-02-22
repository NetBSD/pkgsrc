# $NetBSD: Makefile,v 1.4 2018/02/22 08:56:35 adam Exp $

DISTNAME=	websocket_client-0.47.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/websocket-client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/websocket-client/websocket-client
COMMENT=	WebSocket client module
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} wsdump.py wsdump${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
