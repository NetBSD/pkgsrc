# $NetBSD: Makefile,v 1.14 2022/01/05 15:41:28 wiz Exp $

DISTNAME=	tempora-1.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tempora/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/tempora
COMMENT=	Objects and routines pertaining to date and time
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-jaraco.functools-[0-9]*:../../devel/py-jaraco.functools
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar>=0.9.1:../../devel/py-test-sugar

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} calc-prorate calc-prorate${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}/tests && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
