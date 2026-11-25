# $NetBSD: Makefile,v 1.4 2026/11/25 08:03:43 adam Exp $

DISTNAME=	jsonpointer-3.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonpointer/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/stefankoegl/python-json-pointer
COMMENT=	Library to resolve JSON Pointers according to RFC 6901
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=77:../../devel/py-setuptools

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	jsonpointer

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
