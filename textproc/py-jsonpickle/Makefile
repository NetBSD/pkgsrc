# $NetBSD: Makefile,v 1.8 2020/11/30 20:36:10 adam Exp $

DISTNAME=	jsonpickle-1.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonpickle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jsonpickle.github.io/
COMMENT=	Python library for serializing any arbitrary object graph into JSON
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
.endif

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} tests/runtests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
