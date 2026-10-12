# $NetBSD: Makefile,v 1.79 2026/10/12 13:53:12 wiz Exp $

DISTNAME=	pypdf-6.20.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/py-pdf/pypdf
COMMENT=	Pure-python PDF library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
# fonts
DEPENDS+=	${PYPKGPREFIX}-fonttools>=0:../../fonts/py-fonttools
# image
DEPENDS+=	${PYPKGPREFIX}-Pillow>=8.0.0:../../graphics/py-Pillow
TEST_DEPENDS+=	${PYPKGPREFIX}-test_socket-[0-9]*:../../devel/py-test_socket
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

PYTHON_VERSIONS_INCOMPATIBLE=	310 311
# crypto
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography

USE_LANGUAGES=	# none

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif
# as of 6.20.0
# https://github.com/py-pdf/pypdf/issues/4187
# 37 failed, 1865 passed, 36 skipped, 2 xfailed, 1 xpassed

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
