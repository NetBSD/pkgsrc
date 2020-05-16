# $NetBSD: Makefile,v 1.19 2020/05/16 18:02:59 adam Exp $

DISTNAME=	pytest-django-3.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-django/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pytest-django.readthedocs.io/
COMMENT=	Django plugin for pytest
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.11.1:../../devel/py-setuptools_scm

PYTHON_VERSIONED_DEPENDENCIES=	test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
