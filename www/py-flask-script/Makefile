# $NetBSD: Makefile,v 1.16 2022/04/29 11:56:46 wiz Exp $

DISTNAME=	Flask-Script-2.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Script/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://flask-script.readthedocs.org/en/latest/
COMMENT=	Scripting support for Flask
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
