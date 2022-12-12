# $NetBSD: Makefile,v 1.4 2022/12/12 14:17:11 adam Exp $

DISTNAME=	itemadapter-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/itemadapter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scrapy/itemadapter
COMMENT=	Wrapper providing a common interface for objects of different types
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
