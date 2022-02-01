# $NetBSD: Makefile,v 1.21 2022/02/01 07:21:41 adam Exp $

DISTNAME=	PyICU-2.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyICU/ICU/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyICU/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.pyicu.org/main/pyicu
COMMENT=	Python extension wrapping the ICU C++ libraries
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config

TEST_DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

PYTHON_VERSIONED_DEPENDENCIES=	test:test

.include "../../lang/python/egg.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
