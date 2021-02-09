# $NetBSD: Makefile,v 1.26 2021/02/09 08:51:03 adam Exp $

DISTNAME=	httplib2-0.19.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httplib2/}

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://github.com/httplib2/httplib2
COMMENT=	Comprehensive http client library for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.4.2:../../devel/py-pyparsing

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
do-test:
.if ${_PYTHON_VERSION} == 27
	cd ${WRKSRC}/python2 && ${PYTHONBIN} httplib2test.py
.else
	cd ${WRKSRC}/python3 && ${PYTHONBIN} httplib2test.py
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
