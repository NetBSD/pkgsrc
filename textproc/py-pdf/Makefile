# $NetBSD: Makefile,v 1.5 2023/07/05 22:02:21 wiz Exp $

DISTNAME=	pypdf-3.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/py-pdf/pypdf
COMMENT=	Pure-python PDF library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
# no tests in pypi distfile
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
#TEST_DEPENDS+=	${PYPKGPREFIX}-test_socket-[0-9]*:../../devel/py-test_socket

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

#do-test:
#	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
