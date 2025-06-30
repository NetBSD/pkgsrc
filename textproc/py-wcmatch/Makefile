# $NetBSD: Makefile,v 1.14 2025/06/30 19:47:11 adam Exp $

DISTNAME=	wcmatch-10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wcmatch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/facelessuser/wcmatch
COMMENT=	Wildcard/glob file name matcher
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0.21.1:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-bracex>=2.1.1:../../textproc/py-bracex

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
