# $NetBSD: Makefile,v 1.1 2023/04/10 20:10:51 joerg Exp $

DISTNAME=	django-permissionedforms-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=wagtail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wagtail/django-permissionedforms
COMMENT=	Django extension for offline model instances
LICENSE=	modified-bsd

GITHUB_PROJECT=	django-permissionedforms
GITHUB_TAG=	v${PKGVERSION_NOREV}

PYTHON_VERSIONS_INCOMPATIBLE+=	27

TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

USE_LANGUAGES=		# none

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/coverage-${PYVERSSUFFIX} run -m django test --settings=tests.settings

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
