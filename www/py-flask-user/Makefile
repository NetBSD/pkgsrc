# $NetBSD: Makefile,v 1.1 2014/05/03 02:35:35 rodent Exp $

DISTNAME=	Flask-User-0.4.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/F/Flask-User/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/lingthio/Flask-User
COMMENT=	Customizable user account management for Flask
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-passlib-[0-9]*:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-bcrypt-[0-9]*:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-babel-[0-9]*:../../www/py-flask-babel
DEPENDS+=	${PYPKGPREFIX}-flask-login-[0-9]*:../../www/py-flask-login
DEPENDS+=	${PYPKGPREFIX}-flask-mail-[0-9]*:../../www/py-flask-mail
DEPENDS+=	${PYPKGPREFIX}-flask-sqlalchemy-[0-9]*:../../www/py-flask-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-flask-wtf-[0-9]*:../../www/py-flask-wtf

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

EGG_NAME=	${DISTNAME:S/-/_/1}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
