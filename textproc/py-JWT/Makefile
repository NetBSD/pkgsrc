# $NetBSD: Makefile,v 1.27 2024/11/24 10:13:05 wiz Exp $

DISTNAME=	pyjwt-2.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyjwt/JWT/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyJWT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jpadilla/pyjwt
COMMENT=	JSON Web Token implementation in Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:S/pyjwt/PyJWT/}

# as of 2.10.0
# 1 failed, 285 passed, 4 skipped

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
