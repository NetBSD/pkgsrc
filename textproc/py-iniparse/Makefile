# $NetBSD: Makefile,v 1.16 2025/04/22 20:36:24 wiz Exp $

DISTNAME=	iniparse-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/iniparse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/candlepin/python-iniparse
COMMENT=	Better INI parser for Python
LICENSE=	mit AND python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

# as of 0.5
# 41 failed, 77 passed, 4 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
