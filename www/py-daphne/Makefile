# $NetBSD: Makefile,v 1.9 2018/03/26 00:30:50 joerg Exp $

DISTNAME=	daphne-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/daphne/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django/daphne
COMMENT=	HTTP, HTTP2 and WebSocket protocol server for ASGI
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 34

DEPENDS+=	${PYPKGPREFIX}-asgiref>=2.0:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-autobahn>=0.18:../../www/py-autobahn
DEPENDS+=	${PYPKGPREFIX}-twisted>=17.5:../../net/py-twisted
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} daphne daphne-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
