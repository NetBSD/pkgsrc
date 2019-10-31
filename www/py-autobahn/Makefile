# $NetBSD: Makefile,v 1.30 2019/10/31 10:10:37 adam Exp $

DISTNAME=	autobahn-19.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/autobahn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://crossbar.io/autobahn/
COMMENT=	WebSocket client and server library, WAMP real-time framework
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.7:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-nacl>=1.0.1:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-six>=1.11.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-txaio>=18.8.1:../../devel/py-txaio
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.3.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.8.6:../../devel/py-test
TEST_ENV+=	USE_ASYNCIO=1

PYTHON_VERSIONS_INCOMPATIBLE=	27 # not all parts are supported

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
