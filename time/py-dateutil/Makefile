# $NetBSD: Makefile,v 1.32 2022/01/13 19:31:24 wiz Exp $

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
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun

PYTHON_VERSIONED_DEPENDENCIES=	test:test
PYTHON_VERSIONED_DEPENDENCIES+=	hypothesis:test
PYTHON_VERSIONED_DEPENDENCIES+=	setuptools_scm:build

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
