# $NetBSD: Makefile,v 1.27 2025/03/08 13:03:15 wiz Exp $

DISTNAME=	Flask-User-1.0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-User/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lingthio/Flask-User
COMMENT=	Customizable user account management for Flask
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-flask>=0.9:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-login>=0.2:../../www/py-flask-login
DEPENDS+=	${PYPKGPREFIX}-flask-mail>=0.9:../../www/py-flask-mail
DEPENDS+=	${PYPKGPREFIX}-flask-sqlalchemy>=1.0:../../www/py-flask-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-flask-wtf>=0.9:../../www/py-flask-wtf
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.7:../../security/py-passlib

USE_LANGUAGES=		# none

WHEEL_NAME=	${DISTNAME:tl:S/-/_/}

PYTHON_VERSIONED_DEPENDENCIES+=	bcrypt cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
