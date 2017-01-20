# $NetBSD: Makefile,v 1.1 2017/01/20 17:53:09 kleink Exp $

DISTNAME=	flask-webpack-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/py//}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=nickjj/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://github.com/nickjj/flask-webpack
COMMENT=	Flask extension to manage assets with Webpack
LICENSE=	gnu-gpl-v3

GITHUB_PROJECT=	flask-webpack
GITHUB_TAG=	v${PKGVERSION_NOREV}

EGG_NAME=	${DISTNAME:S/flask-webpack/Flask_Webpack/}

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
