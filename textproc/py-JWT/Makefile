# $NetBSD: Makefile,v 1.31 2026/02/01 17:52:53 wiz Exp $

DISTNAME=	pyjwt-2.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyjwt/JWT/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyJWT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jpadilla/pyjwt
COMMENT=	JSON Web Token implementation in Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
