# $NetBSD: Makefile,v 1.39 2025/03/05 10:57:37 wiz Exp $

DISTNAME=	paste-3.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Paste/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pythonpaste.readthedocs.io/
COMMENT=	Middleware for Python WSGI applications
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-flup-[0-9]*:../../www/py-flup

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
