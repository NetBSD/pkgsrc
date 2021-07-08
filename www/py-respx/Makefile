# $NetBSD: Makefile,v 1.3 2021/07/08 08:41:15 adam Exp $

DISTNAME=	respx-0.17.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/respx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lundberg/respx
COMMENT=	Utility for mocking out the Python HTTPX library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-httpx>=0.18.0:../../www/py-httpx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 36 # py-httpx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
