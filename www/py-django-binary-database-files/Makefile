# $NetBSD: Makefile,v 1.2 2020/08/19 00:29:46 joerg Exp $

DISTNAME=	django-binary-database-files-1.0.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=kimetrica/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kimetrica/django-binary-database-files
COMMENT=	In-database file storage backend for Django
LICENSE=	modified-bsd

GITHUB_PROJECT=	django-binary-database-files
GITHUB_TAG=	cedd9f4608eb0da343cf15cfcaf5400a0754cc28

DEPENDS+=	${PYPKGPREFIX}-django>=2.2:../../www/py-django2

USE_LANGUAGES=		# none
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/django-admin-${PYVERSSUFFIX} test \
	     --pythonpath=. \
	     --settings=binary_database_files.tests.settings \
	     binary_database_files.tests.tests.DatabaseFilesTestCase

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
