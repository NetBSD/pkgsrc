# $NetBSD: Makefile,v 1.21 2025/03/07 16:02:51 adam Exp $

DISTNAME=	django-classy-tags-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-classy-tags/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/ojii/django-classy-tags
COMMENT=	Class based template tags for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
