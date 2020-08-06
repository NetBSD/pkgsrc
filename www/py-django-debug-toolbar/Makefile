# $NetBSD: Makefile,v 1.1 2020/08/06 12:02:30 joerg Exp $

DISTNAME=	django-debug-toolbar-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=jazzband/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/django-debug-toolbar
COMMENT=	Debugging toolbar for Django
LICENSE=	modified-bsd

GITHUB_PROJECT=	django-debug-toolbar
GITHUB_TAG=	${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-sqlparse>=0.2.0:../../databases/py-sqlparse
DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/coverage-${PYVERSSUFFIX} \
	    run -m django test --settings=tests.settings

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
