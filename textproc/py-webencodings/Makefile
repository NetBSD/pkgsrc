# $NetBSD: Makefile,v 1.7 2026/08/16 12:56:40 wiz Exp $

DISTNAME=	webencodings-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/webencodings/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/CourtBouillon/webencodings
COMMENT=	Character encoding for the web
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
