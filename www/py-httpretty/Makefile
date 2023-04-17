# $NetBSD: Makefile,v 1.1 2023/04/17 20:45:04 adam Exp $

DISTNAME=	httpretty-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpretty/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://httpretty.readthedocs.io/
COMMENT=	HTTP client mock for Python
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
