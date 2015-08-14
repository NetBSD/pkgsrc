# $NetBSD: Makefile,v 1.18 2015/08/14 18:52:48 kleink Exp $

DISTNAME=	Flask-WTF-0.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	https://pypi.python.org/packages/source/F/Flask-WTF/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://github.com/lepture/flask-wtf
COMMENT=	Simple integration of Flask and WTForms
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

.include "options.mk"

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-wtforms>=1.0.5:../../www/py-wtforms
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
