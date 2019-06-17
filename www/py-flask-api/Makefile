# $NetBSD: Makefile,v 1.1 2019/06/17 20:56:58 adam Exp $

DISTNAME=	Flask-API-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-API/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.flaskapi.org/
COMMENT=	Browsable web APIs for Flask
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask>=0.12.3:../../www/py-flask

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
