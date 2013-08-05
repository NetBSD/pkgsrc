# $NetBSD: Makefile,v 1.1 2013/08/05 17:51:45 kleink Exp $

DISTNAME=	Flask-Mail-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-Mail/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://pythonhosted.org/Flask-Mail/
COMMENT=	Flask extension for sending email
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	31 32

EGG_NAME=	${DISTNAME:S/-/_/}

DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
