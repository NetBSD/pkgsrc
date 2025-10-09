# $NetBSD: Makefile,v 1.6 2025/10/09 08:01:59 wiz Exp $

DISTNAME=	mdit_py_plugins-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mdit-py-plugins/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/executablebooks/mdit-py-plugins
COMMENT=	Collection of plugins for markdown-it-py
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-markdown-it-py>=2.0.0:../../textproc/py-markdown-it-py
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
