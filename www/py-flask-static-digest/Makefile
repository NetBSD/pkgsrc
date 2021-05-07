# $NetBSD: Makefile,v 1.2 2021/05/07 19:25:20 kleink Exp $

DISTNAME=	flask-static-digest-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=nickjj/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/nickjj/flask-static-digest
COMMENT=	Flask extension for md5 tagging and gzipping static files
LICENSE=	mit

GITHUB_PROJECT=	flask-static-digest
GITHUB_TAG=	v${PKGVERSION_NOREV}

EGG_NAME=	${DISTNAME:S/flask-static-digest/Flask_Static_Digest/}

DEPENDS+=	${PYPKGPREFIX}-flask>=1.0:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
