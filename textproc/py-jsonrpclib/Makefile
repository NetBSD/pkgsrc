# $NetBSD: Makefile,v 1.2 2017/01/01 14:44:01 wiz Exp $

DISTNAME=	jsonrpclib-0.1.7
PKGNAME=	${PYPKGPREFIX}-jsonrpclib-0.1.7
CATEGORIES=	textproc net devel
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonrpclib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/jsonrpclib
COMMENT=	Implementation of the JSON-RPC v2.0 specification
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # as of 0.1.7

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
