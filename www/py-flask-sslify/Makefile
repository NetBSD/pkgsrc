# $NetBSD: Makefile,v 1.5 2017/01/12 12:00:29 rodent Exp $

DISTNAME=	Flask-SSLify-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security www
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-SSLify/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/kennethreitz/flask-sslify
COMMENT=	Force SSL on your Flask app
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
