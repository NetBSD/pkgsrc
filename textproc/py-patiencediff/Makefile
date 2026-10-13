# $NetBSD: Makefile,v 1.11 2026/10/13 09:26:04 wiz Exp $

DISTNAME=	patiencediff-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/patiencediff/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/breezy-team/patiencediff
COMMENT=	Python implementation of the patiencediff algorithm
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 # or later

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=1.5.0:../../devel/py-setuptools-rust

PY_RENAME_BINARIES=	patiencediff

# https://github.com/breezy-team/patiencediff/issues/159
MAKE_ENV+=		PYO3_USE_ABI3_FORWARD_COMPATIBILITY=1

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
