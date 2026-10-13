# $NetBSD: Makefile,v 1.18 2026/10/13 07:08:59 wiz Exp $

DISTNAME=	jellyfish-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jellyfish/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/jpt/jellyfish
COMMENT=	Python library for doing approximate and phonetic matching of strings
LICENSE=	2-clause-bsd

# https://codeberg.org/jpt/jellyfish/issues/237
MAKE_ENV+=		PYO3_USE_ABI3_FORWARD_COMPATIBILITY=1

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
