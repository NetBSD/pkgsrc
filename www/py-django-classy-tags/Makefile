# $NetBSD: Makefile,v 1.20 2023/10/10 16:21:59 adam Exp $

DISTNAME=	django-classy-tags-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-classy-tags/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/ojii/django-classy-tags
COMMENT=	Class based template tags for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
