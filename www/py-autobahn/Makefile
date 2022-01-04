# $NetBSD: Makefile,v 1.33 2022/01/04 20:55:16 wiz Exp $

DISTNAME=	autobahn-20.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
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

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} wamp wamp-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
