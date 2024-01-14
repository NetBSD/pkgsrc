# $NetBSD: Makefile,v 1.9 2024/01/14 09:02:59 wiz Exp $

DISTNAME=	alabaster-0.7.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/alabaster/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/bitprophet/alabaster
COMMENT=	Configurable sidebar-enabled Sphinx theme
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
