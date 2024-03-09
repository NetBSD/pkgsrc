# $NetBSD: Makefile,v 1.14 2024/03/09 06:40:34 adam Exp $

DISTNAME=	django-filter-24.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-filter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/carltongibson/django-filter
COMMENT=	Generic dynamic filtering support for Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
