# $NetBSD: Makefile,v 1.11 2026/11/16 12:11:57 adam Exp $

DISTNAME=	ciso8601-2.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/ciso8601/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/closeio/ciso8601
COMMENT=	Fast ISO8601 date time parser for Python written in C
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz>=0:../../time/py-pytz

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=	c99

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
