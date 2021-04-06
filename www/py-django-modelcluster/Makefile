# $NetBSD: Makefile,v 1.3 2021/04/06 19:04:46 joerg Exp $

DISTNAME=	django-modelcluster-5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=wagtail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wagtail/django-modelcluster
COMMENT=	Django extension for offline model instances
LICENSE=	modified-bsd

GITHUB_PROJECT=	django-modelcluster
GITHUB_TAG=	v${PKGVERSION_NOREV}

PYTHON_VERSIONS_INCOMPATIBLE+=	27

DEPENDS+=	${PYPKGPREFIX}-pytz>=2015.2:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-django-taggit>=0.20:../../www/py-django-taggit
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

USE_LANGUAGES=		# none

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/coverage-${PYVERSSUFFIX} run -m django test --settings=tests.settings

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
