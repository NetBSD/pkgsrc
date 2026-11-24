# $NetBSD: Makefile,v 1.41 2026/11/24 08:02:34 adam Exp $

DISTNAME=	paste-3.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Paste/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pythonpaste.readthedocs.io/
COMMENT=	Middleware for Python WSGI applications
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-flup>=0:../../www/py-flup

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
