# $NetBSD: Makefile,v 1.2 2018/02/02 12:41:30 adam Exp $

DISTNAME=	django-filter-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-filter/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/carltongibson/django-filter
COMMENT=	Generic dynamic filtering support for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-djangorestframework-[0-9]*:../../www/py-djangorestframework

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
