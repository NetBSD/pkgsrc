# $NetBSD: Makefile,v 1.2 2025/07/07 05:58:06 wiz Exp $

DISTNAME=	class-doc-0.2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/class-doc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/danields761/class-doc
COMMENT=	Extract attributes docstrings defined in various ways
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry>=0.12:../../devel/py-poetry
DEPENDS+=	${PYPKGPREFIX}-more-itertools>=5.0.0:../../devel/py-more-itertools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
