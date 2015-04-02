# $NetBSD: Makefile,v 1.8 2015/04/02 22:53:02 rodent Exp $

DISTNAME=	Flask-Bootstrap-3.3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/F/Flask-Bootstrap/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/mbr/flask-bootstrap
COMMENT=	Flask extension for Twitter's Bootstrap
LICENSE=	apache-2.0 AND mit AND modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask>=0.8:../../www/py-flask

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	flask_bootstrap/__init__.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
