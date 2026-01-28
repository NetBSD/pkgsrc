# $NetBSD: Makefile,v 1.13 2026/01/28 11:24:40 adam Exp $

DISTNAME=	django_binary_database_files-1.0.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-binary-database-files/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kimetrica/django-binary-database-files
COMMENT=	In-database file storage backend for Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/django-admin-${PYVERSSUFFIX} test \
	     --pythonpath=. \
	     --settings=binary_database_files.tests.settings \
	     binary_database_files.tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
