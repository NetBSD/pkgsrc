# $NetBSD: Makefile,v 1.13 2025/12/26 10:14:59 adam Exp $

DISTNAME=	itemadapter-0.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/itemadapter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scrapy/itemadapter
COMMENT=	Wrapper providing a common interface for objects of different types
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
