# $NetBSD: Makefile,v 1.4 2020/05/17 20:56:29 adam Exp $

DISTNAME=	dominate-2.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dominate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Knio/dominate
COMMENT=	Python library for creating and manipulating HTML documents
LICENSE=	gnu-lgpl-v3

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
