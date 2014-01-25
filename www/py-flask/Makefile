# $NetBSD: Makefile,v 1.7 2014/01/25 10:30:28 wiz Exp $

DISTNAME=	Flask-0.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://flask.pocoo.org/
COMMENT=	Python web microframework
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-itsdangerous-[0-9]*:../../security/py-itsdangerous
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
