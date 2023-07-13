# $NetBSD: Makefile,v 1.2 2023/07/13 10:03:29 wiz Exp $

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

DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
