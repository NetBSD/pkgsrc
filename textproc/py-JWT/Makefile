# $NetBSD: Makefile,v 1.29 2025/03/03 06:54:35 wiz Exp $

DISTNAME=	pyjwt-2.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyjwt/JWT/}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyJWT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jpadilla/pyjwt
COMMENT=	JSON Web Token implementation in Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools

USE_LANGUAGES=	# none

# as of 2.10.0
# 1 failed, 285 passed, 4 skipped

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
