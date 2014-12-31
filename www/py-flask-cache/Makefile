# $NetBSD: Makefile,v 1.4 2014/12/31 13:57:32 wiz Exp $

DISTNAME=	Flask-Cache-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-Cache/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://packages.python.org/Flask-Cache/
COMMENT=	Cache extension for Flask
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

USE_LANGUAGES=	# empty

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
