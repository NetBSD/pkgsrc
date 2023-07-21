# $NetBSD: Makefile,v 1.23 2023/07/21 06:20:39 adam Exp $

DISTNAME=	gunicorn-21.2.0
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gunicorn/}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://gunicorn.org/
COMMENT=	Python WSGI HTTP server
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
TEST_DEPENDS+=	${PYPKGPREFIX}-gevent-[0-9]*:../../net/py-gevent
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0.5:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.4.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes
PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} gunicorn gunicorn-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
