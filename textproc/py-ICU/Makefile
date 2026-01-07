# $NetBSD: Makefile,v 1.43 2026/01/07 08:49:07 wiz Exp $

DISTNAME=	pyicu-2.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyicu/ICU/}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyICU/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.pyicu.org/main/pyicu
COMMENT=	Python extension wrapping the ICU C++ libraries
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_CXX_FEATURES+=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

.include "../../lang/python/wheel.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
