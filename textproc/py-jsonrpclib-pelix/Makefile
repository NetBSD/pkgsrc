# $NetBSD: Makefile,v 1.12 2025/03/15 20:26:45 adam Exp $

DISTNAME=	jsonrpclib_pelix-0.4.3.4
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
