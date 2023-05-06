# $NetBSD: Makefile,v 1.1 2023/05/06 09:45:03 wiz Exp $

DISTNAME=	docstring-to-markdown-0.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/docstring-to-markdown/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/docstring-to-markdown/
COMMENT=	On-the-fly conversion of Python docstrings to Markdown
LICENSE=	gnu-lgpl-v2.1 # or later

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
