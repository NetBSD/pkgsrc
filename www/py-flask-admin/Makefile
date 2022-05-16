# $NetBSD: Makefile,v 1.30 2022/05/16 15:26:17 kleink Exp $

DISTNAME=	Flask-Admin-1.6.0
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

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	${FIND} ${WRKSRC}/flask_admin/static -type f -exec ${CHMOD} a-x {} +
	${FIND} ${WRKSRC}/flask_admin/templates -type f -exec ${CHMOD} a-x {} +

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
