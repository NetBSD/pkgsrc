# $NetBSD: Makefile,v 1.15 2023/11/05 22:11:37 wiz Exp $

DISTNAME=	Flask-Bootstrap-3.3.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Bootstrap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mbr/flask-bootstrap
COMMENT=	Flask extension for Twitter's Bootstrap
LICENSE=	apache-2.0 AND mit AND modified-bsd

DEPENDS+=	${PYPKGPREFIX}-dominate-[0-9]*:../../textproc/py-dominate
DEPENDS+=	${PYPKGPREFIX}-flask>=0.8:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-visitor-[0-9]*:../../devel/py-visitor

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 312

REPLACE_PYTHON+=	flask_bootstrap/__init__.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
