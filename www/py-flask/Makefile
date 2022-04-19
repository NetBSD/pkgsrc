# $NetBSD: Makefile,v 1.21 2022/04/19 12:07:43 tnn Exp $

DISTNAME=	Flask-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://flask.pocoo.org/
COMMENT=	Python web microframework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-itsdangerous>=0.24:../../security/py-itsdangerous
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=0.15:../../www/py-werkzeug

PYTHON_VERSIONED_DEPENDENCIES+=	click jinja2
PYTHON_VERSIONED_DEPENDENCIES+=	test:test

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} flask flask-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}/tests && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
