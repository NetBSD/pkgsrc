# $NetBSD: Makefile,v 1.9 2024/09/16 19:33:01 adam Exp $

DISTNAME=	django_taggit-6.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-taggit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/django-taggit
COMMENT=	Generic tagging application for Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-django>=4.1:../../www/py-django4
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-djangorestframework-[0-9]*:../../www/py-djangorestframework

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/coverage-${PYVERSSUFFIX} run -m django test --settings=tests.settings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
