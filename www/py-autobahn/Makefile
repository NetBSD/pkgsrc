# $NetBSD: Makefile,v 1.38 2023/06/19 08:14:43 wiz Exp $

DISTNAME=	autobahn-23.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/autobahn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://crossbar.io/autobahn/
COMMENT=	WebSocket client and server library, WAMP real-time framework
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-txaio>=21.2.1:../../devel/py-txaio
DEPENDS+=	${PYPKGPREFIX}-hyperlink>=21.0.0:../../www/py-hyperlink
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.3.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nacl>=0:../../security/py-nacl
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.8.6:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted>=0:../../net/py-twisted
TEST_ENV+=	USE_ASYNCIO=1

USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

DISTUTILS_BUILDDIR_IN_TEST_ENV=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} wamp wamp-${PYVERSSUFFIX}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} xbrnetwork xbrnetwork-${PYVERSSUFFIX}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} xbrnetwork-ui xbrnetwork-ui-${PYVERSSUFFIX}

# doesn't work: collect error with path mismatches between src files and those in build/lib*
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
