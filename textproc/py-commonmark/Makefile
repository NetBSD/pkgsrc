# $NetBSD: Makefile,v 1.7 2026/06/01 19:33:43 adam Exp $

DISTNAME=	commonmark-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/commonmark/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rtfd/CommonMark-py
COMMENT=	Python parser for the CommonMark Markdown spec
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	cmark

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
