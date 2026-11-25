# $NetBSD: Makefile,v 1.1 2026/11/25 10:32:44 adam Exp $

DISTNAME=	django_unfold-0.110.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-unfold/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://unfoldadmin.com/
COMMENT=	Modern Django Admin
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-django>=5.2:../../www/py-django

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
