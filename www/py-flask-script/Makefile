# $NetBSD: Makefile,v 1.10 2014/05/15 14:52:00 kleink Exp $

DISTNAME=	Flask-Script-2.0.3
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
