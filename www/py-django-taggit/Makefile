# $NetBSD: Makefile,v 1.7 2023/04/10 20:03:15 joerg Exp $

DISTNAME=	django-taggit-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-taggit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/django-taggit
COMMENT=	Generic tagging application for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django3
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-djangorestframework-[0-9]*:../../www/py-djangorestframework

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && LC_ALL=C ${PREFIX}/bin/coverage-${PYVERSSUFFIX} run -m django test --settings=tests.settings

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
