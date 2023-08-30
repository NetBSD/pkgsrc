# $NetBSD: Makefile,v 1.10 2023/08/30 13:47:41 adam Exp $

DISTNAME=	django-contrib-comments-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-contrib-comments/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django/django-contrib-comments
COMMENT=	Framework to attach comments to any Django model
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
