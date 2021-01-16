# $NetBSD: Makefile,v 1.5 2021/01/16 10:15:22 adam Exp $

DISTNAME=	django-contrib-comments-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-contrib-comments/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django/django-contrib-comments
COMMENT=	Framework to attach comments to any Django model
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
