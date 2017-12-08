# $NetBSD: Makefile,v 1.3 2017/12/08 20:38:59 joerg Exp $

DISTNAME=	daphne-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/daphne/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django/daphne
COMMENT=	HTTP, HTTP2 and WebSocket protocol server for ASGI
LICENSE=	modified-bsd

USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-asgiref-[0-9]*:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-autobahn>=0.18:../../www/py-autobahn
DEPENDS+=	${PYPKGPREFIX}-twisted>=17.1:../../net/py-twisted

# py-asgiref
PYTHON_VERSIONS_INCOMPATIBLE=	27 34

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/daphne \
		${DESTDIR}${PREFIX}/bin/daphne-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
