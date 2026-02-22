# $NetBSD: Makefile,v 1.45 2026/02/22 11:14:00 wiz Exp $

DISTNAME=	flask-3.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flask/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://flask.pocoo.org/
COMMENT=	Python web microframework
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-blinker>=1.9.0:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-click>=8.1.3:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-itsdangerous>=2.2.0:../../security/py-itsdangerous
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.1.2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=2.1.1:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=3.1.0:../../www/py-werkzeug

USE_LANGUAGES=	# none

# as of 3.1.3
# 1 failed, 476 passed, 6 skipped

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} flask flask-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
