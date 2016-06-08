# $NetBSD: Makefile,v 1.5 2016/06/08 17:43:45 wiz Exp $

DISTNAME=	Flask-Uploads-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Uploads/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://pythonhosted.org/Flask-Uploads/
COMMENT=	Flexible and efficient upload handling for Flask
LICENSE=	mit

USE_LANGUAGES=	#empty

DEPENDS+=	${PYPKGPREFIX}-flask>=0.8:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
