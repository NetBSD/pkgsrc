# $NetBSD: Makefile,v 1.11 2024/10/14 06:45:59 wiz Exp $

DISTNAME=	alabaster-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/alabaster/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/bitprophet/alabaster
COMMENT=	Configurable sidebar-enabled Sphinx theme
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
