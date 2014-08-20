# $NetBSD: Makefile,v 1.1 2014/08/20 13:23:51 wiz Exp $

DISTNAME=	WebOb-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/W/WebOb/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.python.org/pypi/WebOb
COMMENT=	Python module providing WSGI request and response objects
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.0.9:../../converters/py-simplejson

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
