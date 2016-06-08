# $NetBSD: Makefile,v 1.3 2016/06/08 17:43:45 wiz Exp $

DISTNAME=	Flask-REST-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-REST/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/ametaireau/flask-rest/
COMMENT=	Simple REST toolkit for Flask
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
