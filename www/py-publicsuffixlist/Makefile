# $NetBSD: Makefile,v 1.27 2026/04/22 10:26:58 adam Exp $

DISTNAME=	publicsuffixlist-1.0.2.20260422
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
