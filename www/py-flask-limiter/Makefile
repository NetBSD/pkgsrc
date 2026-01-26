# $NetBSD: Makefile,v 1.20 2026/01/26 16:30:24 adam Exp $

DISTNAME=	flask_limiter-4.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Limiter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flask-limiter.readthedocs.org/
COMMENT=	Rate limiting for flask applications
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.4.0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.14.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-flask>=2:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-limits>=3.13:../../devel/py-limits
DEPENDS+=	${PYPKGPREFIX}-ordered-set>=4:../../devel/py-ordered-set
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.3:../../devel/py-typing-extensions
# cli
DEPENDS+=	${PYPKGPREFIX}-rich>=12:../../comms/py-rich
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-restful>=0:../../www/py-flask-restful
# also needs unpackaged 'hiro' for testing

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
