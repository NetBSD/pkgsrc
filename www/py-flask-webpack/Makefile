# $NetBSD: Makefile,v 1.4 2022/04/29 11:56:47 wiz Exp $

DISTNAME=	flask-webpack-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/py//}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=nickjj/}
GITHUB_PROJECT=	flask-webpack
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/nickjj/flask-webpack
COMMENT=	Flask extension to manage assets with Webpack
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

PYTHON_VERSIONS_INCOMPATIBLE=	27

EGG_NAME=	${DISTNAME:S/flask-webpack/Flask_Webpack/}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
