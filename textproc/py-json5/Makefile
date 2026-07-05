# $NetBSD: Makefile,v 1.11 2026/07/05 10:17:52 adam Exp $

DISTNAME=	json5-0.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/json5/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dpranke/pyjson5
COMMENT=	Python implementation of the JSON5 data format
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	pyjson5

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
