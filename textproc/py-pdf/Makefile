# $NetBSD: Makefile,v 1.63 2026/05/10 13:47:51 wiz Exp $

DISTNAME=	pypdf-6.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/py-pdf/pypdf
COMMENT=	Pure-python PDF library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-fonttools>=0:../../fonts/py-fonttools
DEPENDS+=	${PYPKGPREFIX}-Pillow>=8.0.0:../../graphics/py-Pillow
TEST_DEPENDS+=	${PYPKGPREFIX}-test_socket-[0-9]*:../../devel/py-test_socket
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography

USE_LANGUAGES=	# none

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif
# as of 6.11.0
# 89 failed, 1080 passed, 24 skipped, 3 xfailed

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.0:../../devel/py-typing-extensions
.endif

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
