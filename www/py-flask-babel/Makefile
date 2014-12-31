# $NetBSD: Makefile,v 1.3 2014/12/31 13:57:32 wiz Exp $

DISTNAME=	Flask-Babel-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www
MASTER_SITES=	https://pypi.python.org/packages/source/F/Flask-Babel/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/mitsuhiko/flask-babel
COMMENT=	Adds i18n/l10n support to Flask applications
LICENSE=	modified-bsd

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.5:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-speaklater>=1.2:../../devel/py-speaklater
DEPENDS+=	${PYPKGPREFIX}-babel>=1.0:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
