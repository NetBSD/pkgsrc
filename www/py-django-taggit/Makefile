# $NetBSD: Makefile,v 1.1 2020/08/04 00:10:11 joerg Exp $

DISTNAME=	django-taggit-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=jazzband/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/django-taggit/
COMMENT=	Generic tagging application for Django
LICENSE=	modified-bsd

GITHUB_PROJECT=	django-taggit
GITHUB_TAG=	${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
