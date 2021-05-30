# $NetBSD: Makefile,v 1.9 2021/05/30 08:12:34 adam Exp $

DISTNAME=	django-formtools-2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-formtools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://django-formtools.readthedocs.io/
COMMENT=	Collection of assorted utilities for specific form use cases
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-django>=2.2:../../www/py-django2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
