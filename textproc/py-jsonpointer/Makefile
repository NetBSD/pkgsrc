# $NetBSD: Makefile,v 1.1 2026/09/22 17:31:45 ryoon Exp $

DISTNAME=	jsonpointer-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonpointer/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/stefankoegl/python-json-pointer
COMMENT=	Library to resolve JSON Pointers according to RFC 6901
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.1:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
.for bin in jsonpointer
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

do-test:
	cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
