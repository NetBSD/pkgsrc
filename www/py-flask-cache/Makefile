# $NetBSD: Makefile,v 1.5 2016/06/08 17:43:43 wiz Exp $

DISTNAME=	Flask-Cache-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Cache/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://packages.python.org/Flask-Cache/
COMMENT=	Cache extension for Flask
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

USE_LANGUAGES=	# empty

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
