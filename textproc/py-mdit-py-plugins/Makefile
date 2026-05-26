# $NetBSD: Makefile,v 1.7 2026/05/26 09:27:24 adam Exp $

DISTNAME=	mdit_py_plugins-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mdit-py-plugins/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/executablebooks/mdit-py-plugins
COMMENT=	Collection of plugins for markdown-it-py
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-markdown-it-py>=2.0.0:../../textproc/py-markdown-it-py

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
