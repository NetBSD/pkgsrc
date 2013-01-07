# $NetBSD: Makefile,v 1.1 2013/01/07 17:37:37 kleink Exp $

DISTNAME=	Flask-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://flask.pocoo.org/
COMMENT=	Python web microframework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
