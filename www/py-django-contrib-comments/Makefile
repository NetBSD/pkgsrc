# $NetBSD: Makefile,v 1.2 2018/10/15 11:20:14 adam Exp $

DISTNAME=	django-contrib-comments-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-contrib-comments/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django/django-contrib-comments
COMMENT=	Framework to attach comments to any Django model
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
