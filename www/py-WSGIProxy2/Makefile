# $NetBSD: Makefile,v 1.7 2024/11/11 07:29:15 wiz Exp $

DISTNAME=	WSGIProxy2-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WSGIProxy2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gawel/WSGIProxy2
COMMENT=	WSGI Proxy with various http client backends
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-WebOb-[0-9]*:../../www/py-WebOb
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
# circular dependency
#TEST_DEPENDS+=	${PYPKGPREFIX}-WebTest-[0-9]*:../../www/py-WebTest

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
