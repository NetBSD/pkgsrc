# $NetBSD: Makefile,v 1.7 2021/05/12 15:59:16 adam Exp $

DISTNAME=	jsonrpclib-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc net devel
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonrpclib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/joshmarshall/jsonrpclib
COMMENT=	Implementation of the JSON-RPC v2.0 specification
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

PYSETUP=	-c 'from setuptools import setup; setup()'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
