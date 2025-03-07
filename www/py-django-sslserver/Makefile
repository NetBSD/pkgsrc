# $NetBSD: Makefile,v 1.3 2025/03/07 16:02:50 adam Exp $

DISTNAME=	django-sslserver-0.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=teddziuba/}
GITHUB_TAG=	27c6f467524583fc522dc7b6792f166960c60210
GITHUB_PROJECT=	django-sslserver

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/teddziuba/django-sslserver
COMMENT=	SSL-enabled development server for Django
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
