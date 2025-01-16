# $NetBSD: Makefile,v 1.34 2025/01/16 09:39:53 adam Exp $

DISTNAME=	django_import_export-4.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-import-export/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/django-import-export/django-import-export
COMMENT=	Django application and library for importing and exporting data
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=60:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.1.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-diff-match-patch>=20241021:../../textproc/py-diff-match-patch
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-tablib>=3.7.0:../../textproc/py-tablib

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
