# $NetBSD: Makefile,v 1.15 2026/04/16 07:27:12 adam Exp $

DISTNAME=	pybtex-0.26.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pybtex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pybtex.org/
COMMENT=	BibTeX-compatible bibliography processor written in Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-latexcodec>=1.0.4:../../print/py-latexcodec
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.01:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

REPLACE_PYTHON=		src/pybtex/charwidths/make_charwidths.py
PY_RENAME_BINARIES=	pybtex pybtex-convert pybtex-format

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
