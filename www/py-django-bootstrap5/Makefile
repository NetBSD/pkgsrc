# $NetBSD: Makefile,v 1.9 2026/01/04 14:23:37 adam Exp $

DISTNAME=	django_bootstrap5-26.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-bootstrap5/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zostera/django-bootstrap5
COMMENT=	Bootstrap 5 for Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.9.6:../../devel/py-uv-build
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
