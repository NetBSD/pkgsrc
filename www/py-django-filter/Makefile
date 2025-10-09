# $NetBSD: Makefile,v 1.20 2025/10/09 08:01:59 wiz Exp $

DISTNAME=	django_filter-25.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-filter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/carltongibson/django-filter
COMMENT=	Generic dynamic filtering support for Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-django>=5.2:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
