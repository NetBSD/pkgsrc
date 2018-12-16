# $NetBSD: Makefile,v 1.14 2018/12/16 18:22:59 adam Exp $

DISTNAME=	daphne-2.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/daphne/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django/daphne
COMMENT=	HTTP, HTTP2 and WebSocket protocol server for ASGI
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-autobahn>=0.18:../../www/py-autobahn
DEPENDS+=	${PYPKGPREFIX}-twisted>=18.7:../../net/py-twisted
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 34

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} daphne daphne-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
