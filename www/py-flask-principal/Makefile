# $NetBSD: Makefile,v 1.4 2014/12/31 13:57:33 wiz Exp $

DISTNAME=	Flask-Principal-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-Principal/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://pythonhosted.org/Flask-Principal/
COMMENT=	Identity management for Flask
LICENSE=	mit

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
