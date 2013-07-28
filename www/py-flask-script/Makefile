# $NetBSD: Makefile,v 1.1 2013/07/28 17:47:18 kleink Exp $

DISTNAME=	Flask-Script-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-Script/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://flask-script.readthedocs.org/en/latest/
COMMENT=	Scripting support for Flask
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

EGG_NAME=	${DISTNAME:S/-/_/}

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
