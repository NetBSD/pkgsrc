# $NetBSD: Makefile,v 1.14 2019/05/19 07:59:50 adam Exp $

DISTNAME=	Flask-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://flask.pocoo.org/
COMMENT=	Python web microframework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-click>=5.1:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-itsdangerous>=0.24:../../security/py-itsdangerous
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=0.14:../../www/py-werkzeug
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0:../../devel/py-test

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} flask flask-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}/tests && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
