# $NetBSD: Makefile,v 1.9 2025/04/14 08:49:19 adam Exp $

DISTNAME=	ciso8601-2.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/ciso8601/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/closeio/ciso8601
COMMENT=	Fast ISO8601 date time parser for Python written in C
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=	c99

TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
