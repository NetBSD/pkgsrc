# $NetBSD: Makefile,v 1.35 2026/07/19 11:44:56 wiz Exp $

DISTNAME=	websockets-16.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/websockets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aaugustin/websockets
COMMENT=	Implementation of the WebSocket Protocol (RFC 6455)
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

TEST_ENV+=	PYTHONPATH=${WRKSRC}/src
PYTEST_ARGS+=	--import-mode=importlib

PY_RENAME_BINARIES=	websockets

# some files missing from tarball
# https://github.com/python-websockets/websockets/issues/1739
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} ${PYTEST_ARGS} \
		tests/test_datastructures.py \
		tests/test_exports.py \
		tests/test_headers.py \
		tests/test_imports.py \
		tests/test_uri.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
