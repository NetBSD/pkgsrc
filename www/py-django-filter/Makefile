# $NetBSD: Makefile,v 1.22 2026/08/12 22:17:38 wiz Exp $

DISTNAME=	django_filter-26.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-filter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/carltongibson/django-filter
COMMENT=	Generic dynamic filtering support for Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=4:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-django>=5.2:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
