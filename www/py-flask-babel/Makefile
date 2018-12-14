# $NetBSD: Makefile,v 1.9 2018/12/14 08:52:22 adam Exp $

DISTNAME=	Flask-Babel-0.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Babel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mitsuhiko/flask-babel
COMMENT=	Adds i18n/l10n support to Flask applications
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-babel>=2.3:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.5:../../textproc/py-jinja2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
