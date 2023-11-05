# $NetBSD: Makefile,v 1.9 2023/11/05 22:11:37 wiz Exp $

DISTNAME=	dominate-2.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dominate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Knio/dominate
COMMENT=	Python library for creating and manipulating HTML documents
LICENSE=	gnu-lgpl-v3

PYTHON_VERSIONED_DEPENDENCIES=	test:test
PYTHON_VERSIONS_INCOMPATIBLE=	312

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
