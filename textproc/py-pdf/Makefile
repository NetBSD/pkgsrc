# $NetBSD: Makefile,v 1.86 2026/11/10 13:21:45 adam Exp $

DISTNAME=	pypdf-7.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/py-pdf/pypdf
COMMENT=	Pure-python PDF library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
# crypto
DEPENDS+=	${PYPKGPREFIX}-cryptography>=43:../../security/py-cryptography
# fonts
DEPENDS+=	${PYPKGPREFIX}-fonttools>=0:../../fonts/py-fonttools
# image
DEPENDS+=	${PYPKGPREFIX}-Pillow>=8.0.0:../../graphics/py-Pillow
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test_socket>=0:../../devel/py-test_socket
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=0:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=0:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml>=0:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif
# as of 7.0.0
# 2394 passed, 33 skipped, 56 deselected, 7 xfailed
do-test:
	${RUN} cd ${WRKSRC}/${PYSETUPSUBDIR} && \
	${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} -m "not samples"

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
