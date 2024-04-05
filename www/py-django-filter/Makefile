# $NetBSD: Makefile,v 1.15 2024/04/05 10:41:31 adam Exp $

DISTNAME=	django-filter-24.2
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
