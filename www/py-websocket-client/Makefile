# $NetBSD: Makefile,v 1.17 2022/07/02 07:59:00 adam Exp $

DISTNAME=	websocket-client-1.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/websocket-client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/websocket-client/websocket-client
COMMENT=	WebSocket client module
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-websockets-[0-9]*:../../www/py-websockets

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} wsdump wsdump-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
