# $NetBSD: Makefile,v 1.19 2022/01/04 20:55:26 wiz Exp $

DISTNAME=	Flask-Login-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Login/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://flask-login.readthedocs.org/
COMMENT=	User session management for Flask
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
