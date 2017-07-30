# $NetBSD: Makefile,v 1.21 2017/07/30 22:32:27 wiz Exp $

DISTNAME=	Flask-WTF-0.14.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-WTF/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/lepture/flask-wtf
COMMENT=	Simple integration of Flask and WTForms
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

.include "options.mk"

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-wtforms>=1.0.5:../../www/py-wtforms
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
