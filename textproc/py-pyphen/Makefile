# $NetBSD: Makefile,v 1.23 2026/08/14 12:18:53 adam Exp $

DISTNAME=	pyphen-0.18.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyphen/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://pyphen.org/
COMMENT=	Pure Python module to hyphenate text
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR mpl-1.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
