# $NetBSD: Makefile,v 1.15 2014/11/25 09:34:30 kleink Exp $

DISTNAME=	Flask-WTF-0.10.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	https://pypi.python.org/packages/source/F/Flask-WTF/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://github.com/lepture/flask-wtf
COMMENT=	Simple integration of Flask and WTForms
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

EGG_NAME=	${DISTNAME:S/-/_/1}

.include "options.mk"

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-wtforms>=1.0.5:../../www/py-wtforms
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
