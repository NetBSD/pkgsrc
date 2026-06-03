# $NetBSD: Makefile,v 1.29 2026/06/03 10:52:03 adam Exp $

DISTNAME=	idna-3.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/idna/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kjd/idna
COMMENT=	Python module for Internationalized Domain Names in Applications (IDNA)
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	idna

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
