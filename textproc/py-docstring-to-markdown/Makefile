# $NetBSD: Makefile,v 1.2 2023/11/05 09:49:49 wiz Exp $

DISTNAME=	docstring-to-markdown-0.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/docstring-to-markdown/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/docstring-to-markdown/
COMMENT=	On-the-fly conversion of Python docstrings to Markdown
LICENSE=	gnu-lgpl-v2.1 # or later

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
