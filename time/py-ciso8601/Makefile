# $NetBSD: Makefile,v 1.5 2023/07/11 05:39:25 nia Exp $

DISTNAME=	ciso8601-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/ciso8601/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/closeio/ciso8601
COMMENT=	Fast ISO8601 date time parser for Python written in C
LICENSE=	mit

# error: 'for' loop initial declarations are only allowed in C99 mode
USE_LANGUAGES=	c99

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
