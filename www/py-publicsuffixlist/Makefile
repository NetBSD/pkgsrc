# $NetBSD: Makefile,v 1.28 2026/07/07 12:51:03 adam Exp $

DISTNAME=	publicsuffixlist-1.0.2.20260707
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/publicsuffixlist/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ko-zu/psl
COMMENT=	Public Suffix List parser implementation
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
# update
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	publicsuffixlist-download

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
