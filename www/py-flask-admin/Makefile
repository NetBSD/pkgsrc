# $NetBSD: Makefile,v 1.22 2019/11/08 13:20:16 adam Exp $

DISTNAME=	Flask-Admin-1.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Admin/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/flask-admin/flask-admin
COMMENT=	Simple and extensible administrative interface framework for Flask
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask>=0.7:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-wtforms-[0-9]*:../../www/py-wtforms

USE_LANGUAGES=	# none

post-extract:
	${FIND} ${WRKSRC}/flask_admin/static -type f -exec ${CHMOD} a-x {} +
	${FIND} ${WRKSRC}/flask_admin/templates -type f -exec ${CHMOD} a-x {} +

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
