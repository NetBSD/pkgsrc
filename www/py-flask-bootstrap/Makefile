# $NetBSD: Makefile,v 1.10 2017/07/30 22:32:26 wiz Exp $

DISTNAME=	Flask-Bootstrap-3.3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Bootstrap/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/mbr/flask-bootstrap
COMMENT=	Flask extension for Twitter's Bootstrap
LICENSE=	apache-2.0 AND mit AND modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask>=0.8:../../www/py-flask

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	flask_bootstrap/__init__.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
