# $NetBSD: Makefile,v 1.5 2022/01/04 20:55:27 wiz Exp $

DISTNAME=	Flask-REST-1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-REST/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/ametaireau/flask-rest/
COMMENT=	Simple REST toolkit for Flask
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
