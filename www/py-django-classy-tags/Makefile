# $NetBSD: Makefile,v 1.19 2023/07/13 10:03:26 wiz Exp $

DISTNAME=	django-classy-tags-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-classy-tags/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/ojii/django-classy-tags
COMMENT=	Class based template tags for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
