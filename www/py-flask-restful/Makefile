# $NetBSD: Makefile,v 1.3 2020/03/21 08:59:45 adam Exp $

DISTNAME=	Flask-RESTful-0.3.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-RESTful/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/flask-restful/flask-restful
COMMENT=	Simple framework for creating REST APIs
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-aniso8601>=0.82:../../time/py-aniso8601
DEPENDS+=	${PYPKGPREFIX}-flask>=0.8:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-six>=1.3.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
