# $NetBSD: Makefile,v 1.24 2022/07/18 19:09:23 adam Exp $

DISTNAME=	Flask-2.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://flask.pocoo.org/
COMMENT=	Python web microframework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-itsdangerous>=2.0:../../security/py-itsdangerous
DEPENDS+=	${PYPKGPREFIX}-click>=8.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=2.0:../../www/py-werkzeug
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${_PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=3.6.0:../../devel/py-importlib-metadata
.endif

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} flask flask-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
