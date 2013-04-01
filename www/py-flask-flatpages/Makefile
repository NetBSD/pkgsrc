# $NetBSD: Makefile,v 1.2 2013/04/01 16:52:47 kleink Exp $

DISTNAME=	Flask-FlatPages-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-FlatPages/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/SimonSapin/Flask-FlatPages
COMMENT=	Provides flat static pages to a Flask application
LICENSE=	modified-bsd

EGG_NAME=	${DISTNAME:S/-/_/}
USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
