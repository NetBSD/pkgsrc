# $NetBSD: Makefile,v 1.9 2023/11/05 20:20:54 wiz Exp $

DISTNAME=	Flask-Limiter-3.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Limiter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flask-limiter.readthedocs.org/
COMMENT=	Rate limiting for flask applications
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-flask>=2:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-ordered-set>=4:../../devel/py-ordered-set
DEPENDS+=	${PYPKGPREFIX}-rich>=12:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-limits>=2.8:../../devel/py-limits
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-restful>=0:../../www/py-flask-restful
# also needs unpackaged 'hiro' for testing

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
