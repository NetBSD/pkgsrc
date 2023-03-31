# $NetBSD: Makefile,v 1.1 2023/03/31 01:00:38 joerg Exp $

DISTNAME=	django-sslserver-0.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=teddziuba/}
GITHUB_TAG=	27c6f467524583fc522dc7b6792f166960c60210
GITHUB_PROJECT=	django-sslserver

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/teddziuba/django-sslserver
COMMENT=	SSL-enabled development server for Django
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django>=1.8:../../www/py-django

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
