# $NetBSD: Makefile,v 1.13 2022/04/29 11:56:46 wiz Exp $

DISTNAME=	Flask-Testing-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Testing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jarus/flask-testing
COMMENT=	Unit testing for Flask
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
