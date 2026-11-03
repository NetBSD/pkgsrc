# $NetBSD: Makefile,v 1.33 2026/11/03 14:09:28 adam Exp $

DISTNAME=	django_mptt-0.21.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-mptt/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django-mptt/django-mptt
COMMENT=	Utilities for implementing Modified Preorder Tree Traversal
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-django-js-asset>=4.0:../../www/py-django-js-asset

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
