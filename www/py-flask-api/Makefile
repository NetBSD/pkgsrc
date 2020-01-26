# $NetBSD: Makefile,v 1.2 2020/01/26 17:32:23 rillig Exp $

DISTNAME=	Flask-API-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-API/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.flaskapi.org/
COMMENT=	Browsable web APIs for Flask
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask>=0.12.3:../../www/py-flask

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
