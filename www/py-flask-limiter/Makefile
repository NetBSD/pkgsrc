# $NetBSD: Makefile,v 1.1 2015/04/02 23:26:50 rodent Exp $
#

DISTNAME=	Flask-Limiter-0.7.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/F/Flask-Limiter/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://flask-limiter.readthedocs.org/
COMMENT=	Rate limiting for flask applications
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-limits-[0-9]*:../../devel/py-limits
DEPENDS+=	${PYPKGPREFIX}-flask>=0.8:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/-/_/1}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
