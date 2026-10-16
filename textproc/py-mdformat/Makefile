# $NetBSD: Makefile,v 1.2 2026/10/16 18:30:55 adam Exp $

DISTNAME=	mdformat-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mdformat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hukkin/mdformat
COMMENT=	CommonMark compliant Markdown formatter
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-markdown-it-py>=1:../../textproc/py-markdown-it-py

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	mdformat

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
