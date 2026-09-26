# $NetBSD: Makefile,v 1.31 2026/09/26 10:15:08 wiz Exp $

DISTNAME=	idna-3.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/idna/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kjd/idna
COMMENT=	Python module for Internationalized Domain Names in Applications (IDNA)
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=0:../../devel/py-hypothesis

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	idna

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
