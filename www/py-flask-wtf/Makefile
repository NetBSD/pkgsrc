# $NetBSD: Makefile,v 1.23 2020/05/11 09:29:11 kleink Exp $

DISTNAME=	Flask-WTF-0.14.3
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
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-babelex-[0-9]*:../../www/py-flask-babelex

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
