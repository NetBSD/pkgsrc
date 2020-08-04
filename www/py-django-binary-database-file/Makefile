# $NetBSD: Makefile,v 1.1 2020/08/04 01:15:13 joerg Exp $

DISTNAME=	django-binary-database-1.0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=kimetrica/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kimetrica/django-binary-database-files
COMMENT=	In-database file storage backend for Django
LICENSE=	modified-bsd

GITHUB_PROJECT=	django-binary-database-files
GITHUB_TAG=	34afac4439f62e62aefd77cc3438fb9888aa8aa5

DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django

USE_LANGUAGES=		# none
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

USE_LANGUAGES=		# none

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/django-admin-${PYVERSSUFFIX} test \
	     --pythonpath=. \
	     --settings=binary_database_files.tests.settings \
	     binary_database_files.tests.tests.DatabaseFilesTestCase

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
