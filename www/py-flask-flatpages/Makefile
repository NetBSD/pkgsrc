# $NetBSD: Makefile,v 1.4 2014/12/31 13:57:32 wiz Exp $

DISTNAME=	Flask-FlatPages-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-FlatPages/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/SimonSapin/Flask-FlatPages
COMMENT=	Provides flat static pages to a Flask application
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
