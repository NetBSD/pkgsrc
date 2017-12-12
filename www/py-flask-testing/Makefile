# $NetBSD: Makefile,v 1.10 2017/12/12 10:07:26 adam Exp $

DISTNAME=	Flask-Testing-0.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Testing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jarus/flask-testing
COMMENT=	Unit testing for Flask
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
.include "../../lang/python/pyversion.mk"
.if "${PYPKGPREFIX}" == "py27"
BUILD_DEPENDS+=	${PYPKGPREFIX}-twill-[0-9]*:../../www/py-twill
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
