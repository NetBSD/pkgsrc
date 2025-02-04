# $NetBSD: Makefile,v 1.16 2025/02/04 13:15:38 adam Exp $

DISTNAME=	flask_limiter-3.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Limiter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flask-limiter.readthedocs.org/
COMMENT=	Rate limiting for flask applications
LICENSE=	mit

WHEEL_NAME=	Flask_Limiter-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-flask>=2:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-limits>=3.13:../../devel/py-limits
DEPENDS+=	${PYPKGPREFIX}-ordered-set>=4:../../devel/py-ordered-set
DEPENDS+=	${PYPKGPREFIX}-rich>=12:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-restful>=0:../../www/py-flask-restful
# also needs unpackaged 'hiro' for testing

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
