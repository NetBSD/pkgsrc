# $NetBSD: Makefile,v 1.2 2014/01/12 09:45:25 wiz Exp $

DISTNAME=	Flask-Principal-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-Principal/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://pythonhosted.org/Flask-Principal/
COMMENT=	Identity management for Flask
LICENSE=	mit

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCLUDE_3X=	yes

EGG_NAME=	${DISTNAME:S/-/_/}

DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
