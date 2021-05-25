# $NetBSD: Makefile,v 1.3 2021/05/25 04:55:46 adam Exp $

DISTNAME=	django-taggit-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-taggit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/django-taggit
COMMENT=	Generic tagging application for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=2.2:../../www/py-django
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

USE_LANGUAGES=		# none

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/coverage-${PYVERSSUFFIX} run -m django test --settings=tests.settings

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
