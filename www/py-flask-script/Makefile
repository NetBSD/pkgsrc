# $NetBSD: Makefile,v 1.13 2016/06/08 17:43:46 wiz Exp $

DISTNAME=	Flask-Script-2.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Script/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://flask-script.readthedocs.org/en/latest/
COMMENT=	Scripting support for Flask
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
