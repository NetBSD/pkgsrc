# $NetBSD: Makefile,v 1.36 2023/03/29 09:34:14 wiz Exp $

DISTNAME=	python-dateutil-2.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	1
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-dateutil/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dateutil/dateutil
COMMENT=	Extensions to the standard datetime module
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=1.5:../../lang/py-six

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} != 207
# freezegun is only available for python 3
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
.endif

PYTHON_VERSIONED_DEPENDENCIES=	test:test
PYTHON_VERSIONED_DEPENDENCIES+=	hypothesis:test
PYTHON_VERSIONED_DEPENDENCIES+=	setuptools_scm:build
PYTHON_VERSIONED_DEPENDENCIES+= pip:build

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
