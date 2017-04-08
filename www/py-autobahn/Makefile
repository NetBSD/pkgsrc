# $NetBSD: Makefile,v 1.2 2017/04/08 21:44:55 adam Exp $

DISTNAME=	autobahn-0.18.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/autobahn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/autobahn
COMMENT=	WebSocket client and server library, WAMP real-time framework
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-txaio-[0-9]*:../../devel/py-txaio

# actually TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-unittest2-[0-9]*:../../devel/py-unittest2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
