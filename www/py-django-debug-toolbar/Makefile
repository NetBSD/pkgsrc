# $NetBSD: Makefile,v 1.10 2025/01/14 08:12:44 adam Exp $

DISTNAME=	django_debug_toolbar-5.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-debug-toolbar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/django-debug-toolbar
COMMENT=	Debugging toolbar for Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-sqlparse>=0.2.0:../../databases/py-sqlparse
DEPENDS+=	${PYPKGPREFIX}-django>=4.2.9:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
