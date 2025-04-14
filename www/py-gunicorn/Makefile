# $NetBSD: Makefile,v 1.27 2025/04/14 19:12:54 adam Exp $

DISTNAME=	gunicorn-23.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gunicorn/}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://gunicorn.org/
COMMENT=	Python WSGI HTTP server
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
TEST_DEPENDS+=	${PYPKGPREFIX}-gevent-[0-9]*:../../net/py-gevent
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} gunicorn gunicorn-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
