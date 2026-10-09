# $NetBSD: Makefile,v 1.2 2026/10/09 03:49:02 adam Exp $

DISTNAME=	jsonpointer-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonpointer/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/stefankoegl/python-json-pointer
COMMENT=	Library to resolve JSON Pointers according to RFC 6901
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.1:../../devel/py-setuptools

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	jsonpointer

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
