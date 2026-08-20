# $NetBSD: Makefile,v 1.15 2026/08/20 11:02:39 adam Exp $

DISTNAME=	django_debug_toolbar-7.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-debug-toolbar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/django-debug-toolbar
COMMENT=	Debugging toolbar for Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-sqlparse>=0.2:../../databases/py-sqlparse
DEPENDS+=	${PYPKGPREFIX}-django>=5.2:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
