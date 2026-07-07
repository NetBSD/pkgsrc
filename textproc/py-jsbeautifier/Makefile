# $NetBSD: Makefile,v 1.27 2026/07/07 12:49:23 adam Exp $

DISTNAME=	jsbeautifier-2.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsbeautifier/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://beautifier.io/
COMMENT=	JavaScript unobfuscator and beautifier
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-editorconfig-core>=0.12.2:../../devel/py-editorconfig-core

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	js-beautify

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
