# $NetBSD: Makefile,v 1.14 2023/08/28 09:55:49 adam Exp $

DISTNAME=	tzdata-2023.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tzdata/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python/tzdata
COMMENT=	Provider of IANA time zone data
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
