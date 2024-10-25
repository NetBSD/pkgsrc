# $NetBSD: Makefile,v 1.41 2024/10/25 10:55:14 adam Exp $

DISTNAME=	autobahn-24.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/autobahn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/crossbario/autobahn-python
COMMENT=	WebSocket client and server library, WAMP real-time framework
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-txaio>=21.2.1:../../devel/py-txaio
DEPENDS+=	${PYPKGPREFIX}-hyperlink>=21.0.0:../../www/py-hyperlink
DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.3.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nacl>=0:../../security/py-nacl
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.8.6:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted>=0:../../net/py-twisted

USE_LANGUAGES=	c

BUILDLINK_TRANSFORM+=	rm:-march=native

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} wamp wamp-${PYVERSSUFFIX}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} xbrnetwork xbrnetwork-${PYVERSSUFFIX}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} xbrnetwork-ui xbrnetwork-ui-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
