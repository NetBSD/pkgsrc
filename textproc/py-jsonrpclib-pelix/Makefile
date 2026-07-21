# $NetBSD: Makefile,v 1.14 2026/07/21 10:59:58 adam Exp $

DISTNAME=	jsonrpclib_pelix-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonrpclib-pelix/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tcalmant/jsonrpclib
COMMENT=	Implementation of the JSON-RPC v2.0 specification
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
