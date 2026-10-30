# $NetBSD: Makefile,v 1.17 2026/10/30 19:28:43 adam Exp $

DISTNAME=	iniparse-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/iniparse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/candlepin/python-iniparse
COMMENT=	Better INI parser for Python
LICENSE=	mit AND python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools

USE_LANGUAGES=	# none

# as of 0.5
# 41 failed, 77 passed, 4 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
