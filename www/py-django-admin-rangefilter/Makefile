# $NetBSD: Makefile,v 1.34 2024/07/24 06:49:12 adam Exp $

DISTNAME=	django_admin_rangefilter-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-admin-rangefilter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/silentsokolov/django-admin-rangefilter
COMMENT=	Add the filter by a custom date range on the admin UI
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
