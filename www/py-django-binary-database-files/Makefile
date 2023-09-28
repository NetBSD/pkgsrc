# $NetBSD: Makefile,v 1.9 2023/09/28 22:26:33 joerg Exp $

DISTNAME=	django-binary-database-files-1.0.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-binary-database-files/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kimetrica/django-binary-database-files
COMMENT=	In-database file storage backend for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

EXTRACT_USING=	bsdtar

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/django-admin-${PYVERSSUFFIX} test \
	     --pythonpath=. \
	     --settings=binary_database_files.tests.settings \
	     binary_database_files.tests.tests.DatabaseFilesTestCase

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
