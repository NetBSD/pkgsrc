# $NetBSD: Makefile,v 1.9 2014/01/12 09:45:25 wiz Exp $

DISTNAME=	Flask-WTF-0.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	https://pypi.python.org/packages/source/F/Flask-WTF/
FETCH_USING=	curl

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://github.com/lepture/flask-wtf
COMMENT=	Simple integration of Flask and WTForms
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCLUDE_3X=	yes

EGG_NAME=	${DISTNAME:S/-/_/1}

.include "options.mk"

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-wtforms>=1.0.5<2.0:../../www/py-wtforms
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
