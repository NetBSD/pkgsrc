# $NetBSD: Makefile,v 1.1 2014/05/03 01:38:37 rodent Exp $

DISTNAME=	Flask-SSLify-0.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security www
MASTER_SITES=	https://pypi.python.org/packages/source/F/Flask-SSLify/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/kennethreitz/flask-sslify
COMMENT=	Force SSL on your Flask app
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
