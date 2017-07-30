# $NetBSD: Makefile,v 1.6 2017/07/30 22:32:26 wiz Exp $

DISTNAME=	Flask-Babel-0.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Babel/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/mitsuhiko/flask-babel
COMMENT=	Adds i18n/l10n support to Flask applications
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.5:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-speaklater>=1.2:../../devel/py-speaklater
DEPENDS+=	${PYPKGPREFIX}-babel>=2.3:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
