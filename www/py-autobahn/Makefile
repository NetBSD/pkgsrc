# $NetBSD: Makefile,v 1.48 2025/12/26 08:57:30 adam Exp $

DISTNAME=	autobahn-25.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/autobahn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/crossbario/autobahn-python
COMMENT=	WebSocket client and server library, WAMP real-time framework
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cbor2>=5.2.0:../../devel/py-cbor2
DEPENDS+=	${PYPKGPREFIX}-cffi>=2.0.0:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-hyperlink>=21.0.0:../../www/py-hyperlink
DEPENDS+=	${PYPKGPREFIX}-msgpack>=1.0.2:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-txaio>=25.12.2:../../devel/py-txaio
DEPENDS+=	${PYPKGPREFIX}-ujson>=4.0.2:../../textproc/py-ujson
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.3.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nacl>=0:../../security/py-nacl
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.8.6:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted>=0:../../net/py-twisted

BUILDLINK_TRANSFORM+=	rm:-march=native

MAKE_ENV+=	PYUBJSON_NO_EXTENSION=1

PYTHON_VERSIONS_INCOMPATIBLE=	310

post-install:
.for bin in flatc wamp
	cd ${DESTDIR}${PREFIX}/bin && ${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/autobahn/nvx/_nvx_utf8validator.[co]
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/autobahn/nvx/_nvx_xormasker.[co]

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
