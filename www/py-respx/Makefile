# $NetBSD: Makefile,v 1.5 2021/10/22 11:13:26 adam Exp $

DISTNAME=	respx-0.18.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/respx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lundberg/respx
COMMENT=	Utility for mocking out the Python HTTPX library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-httpx>=0.20.0:../../www/py-httpx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 36 # py-httpx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
