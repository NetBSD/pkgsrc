# $NetBSD: Makefile,v 1.3 2022/01/04 20:55:28 wiz Exp $

DISTNAME=	flask-webpack-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/py//}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=nickjj/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/nickjj/flask-webpack
COMMENT=	Flask extension to manage assets with Webpack
LICENSE=	gnu-gpl-v3

GITHUB_PROJECT=	flask-webpack
GITHUB_TAG=	v${PKGVERSION_NOREV}

EGG_NAME=	${DISTNAME:S/flask-webpack/Flask_Webpack/}

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
