# $NetBSD: Makefile,v 1.9 2023/10/28 19:57:21 wiz Exp $

DISTNAME=	wcmatch-8.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wcmatch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/facelessuser/wcmatch
COMMENT=	Wildcard/glob file name matcher
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0.21.1:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-bracex>=2.1.1:../../textproc/py-bracex

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
