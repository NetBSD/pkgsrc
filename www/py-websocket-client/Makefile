# $NetBSD: Makefile,v 1.2 2017/10/11 06:35:50 adam Exp $

DISTNAME=	websocket_client-0.44.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/websocket-client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/websocket-client/websocket-client
COMMENT=	WebSocket client module
LICENSE=	gnu-lgpl-v3

PYTHON_VERSIONS_ACCEPTED=	36 35 34

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=		# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} wsdump.py wsdump${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
