# $NetBSD: Makefile,v 1.23 2023/03/29 09:34:15 wiz Exp $

DISTNAME=	pytest-django-3.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-django/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pytest-django.readthedocs.io/
COMMENT=	Django plugin for pytest
LICENSE=	modified-bsd

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} == 207
DEPENDS+=	${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
.endif

PYTHON_VERSIONED_DEPENDENCIES=	test
PYTHON_VERSIONED_DEPENDENCIES=	setuptools_scm:build

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
