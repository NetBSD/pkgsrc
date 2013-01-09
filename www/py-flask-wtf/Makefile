# $NetBSD: Makefile,v 1.2 2013/01/09 19:02:44 kleink Exp $

DISTNAME=	Flask-WTF-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-WTF/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://github.com/ajford/flask-wtf
COMMENT=	Simple integration of Flask and WTForms
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

EGG_NAME=	${DISTNAME:S/-/_/}

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-wtforms>=1.0:../../www/py-wtforms

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
