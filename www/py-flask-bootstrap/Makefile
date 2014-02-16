# $NetBSD: Makefile,v 1.3 2014/02/16 23:46:55 rodent Exp $

DISTNAME=	Flask-Bootstrap-3.1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/F/Flask-Bootstrap/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/mbr/flask-bootstrap
COMMENT=	Flask extension for Twitter's Bootstrap
LICENSE=	apache-2.0 AND mit AND modified-bsd

USE_LANGUAGES=	# none
EGG_NAME=	${DISTNAME:S/-/_/1}

REPLACE_PYTHON+=	flask_bootstrap/__init__.py

DEPENDS+=	${PYPKGPREFIX}-flask>=0.8:../../www/py-flask
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
