# $NetBSD: Makefile,v 1.51 2026/09/04 06:56:08 adam Exp $

DISTNAME=	autobahn-26.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/autobahn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/crossbario/autobahn-python
COMMENT=	WebSocket client and server library, WAMP real-time framework
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
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
# Upstream attempts to build for x86-64-v2 by default.  This has two
# problems:
#   - Many compilers do not support -march=x86-64-v2.
#   - pkgsrc must build for the OS's default CPU target, and the default
#     expectation (true for NetBSD) is regular x86-64.
# Resolve this via transforming away -v2.
BUILDLINK_TRANSFORM+=	opt:-march=x86-64-v2:-march=x86-64

# \todo Extend the fix to use armv8 instead of armv8-a, as it appears
# the build system will produce code that workson RPI4 but not RPI3.

MAKE_ENV+=	PYUBJSON_NO_EXTENSION=1

PY_RENAME_BINARIES=	flatc wamp

PYTHON_VERSIONS_INCOMPATIBLE=	310

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/autobahn/nvx/_nvx_utf8validator.[co]
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/autobahn/nvx/_nvx_xormasker.[co]

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
