# $NetBSD: Makefile,v 1.36 2024/11/11 07:29:17 wiz Exp $

DISTNAME=	django_admin_rangefilter-0.13.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-admin-rangefilter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/silentsokolov/django-admin-rangefilter
COMMENT=	Add the filter by a custom date range on the admin UI
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
