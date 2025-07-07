# $NetBSD: Makefile,v 1.39 2025/07/07 05:58:07 wiz Exp $

DISTNAME=	django_import_export-4.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-import-export/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/django-import-export/django-import-export
COMMENT=	Django application and library for importing and exporting data
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.1.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-diff-match-patch>=20241021:../../textproc/py-diff-match-patch
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-tablib>=3.7.0:../../textproc/py-tablib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
