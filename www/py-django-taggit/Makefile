# $NetBSD: Makefile,v 1.2 2020/08/04 00:29:03 joerg Exp $

DISTNAME=	django-taggit-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=jazzband/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/django-taggit/
COMMENT=	Generic tagging application for Django
LICENSE=	modified-bsd

GITHUB_PROJECT=	django-taggit
GITHUB_TAG=	${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

USE_LANGUAGES=		# none

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/coverage-${PYVERSSUFFIX} run -m django test --settings=tests.settings

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
