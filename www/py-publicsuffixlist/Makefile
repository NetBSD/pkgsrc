# $NetBSD: Makefile,v 1.31 2026/11/12 11:36:01 adam Exp $

DISTNAME=	publicsuffixlist-1.1.2.20261112
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/publicsuffixlist/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ko-zu/psl
COMMENT=	Public Suffix List parser implementation
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
# update
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	publicsuffixlist-download

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
