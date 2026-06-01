# $NetBSD: Makefile,v 1.28 2026/06/01 13:43:48 wiz Exp $

DISTNAME=	idna-3.17
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
