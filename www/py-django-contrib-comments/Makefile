# $NetBSD: Makefile,v 1.1 2017/05/09 20:22:34 adam Exp $

DISTNAME=	django-contrib-comments-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-contrib-comments/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django/django-contrib-comments
COMMENT=	Framework to attach comments to any Django model
LICENSE=	modified-bsd

USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django>=1.8:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
