# $NetBSD: Makefile,v 1.37 2024/06/11 09:09:28 adam Exp $

DISTNAME=	paste-3.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Paste/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pythonpaste.readthedocs.io/
COMMENT=	Middleware for Python WSGI applications
LICENSE=	mit

WHEEL_NAME=	Paste-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-flup-[0-9]*:../../www/py-flup

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
