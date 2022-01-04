# $NetBSD: Makefile,v 1.15 2022/01/04 20:55:27 wiz Exp $

DISTNAME=	Flask-Security-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Security/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://pythonhosted.org/Flask-Security/
COMMENT=	Simple security for Flask apps
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-babel>=1.3:../../devel/py-babel
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
DEPENDS+=	${PYPKGPREFIX}-flask>=0.11:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-babelex>=0.9.3:../../www/py-flask-babelex
DEPENDS+=	${PYPKGPREFIX}-flask-login>=0.3.0:../../www/py-flask-login
DEPENDS+=	${PYPKGPREFIX}-flask-mail>=0.7.3:../../www/py-flask-mail
DEPENDS+=	${PYPKGPREFIX}-flask-principal>=0.3.3:../../www/py-flask-principal
DEPENDS+=	${PYPKGPREFIX}-flask-wtf>=0.13.1:../../www/py-flask-wtf
DEPENDS+=	${PYPKGPREFIX}-itsdangerous>=0.21:../../security/py-itsdangerous
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.7:../../security/py-passlib

USE_LANGUAGES=	# empty

post-extract:
	${FIND} ${WRKSRC} -type f -name .DS_Store -exec ${RM} {} \;

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
