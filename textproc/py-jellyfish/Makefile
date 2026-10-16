# $NetBSD: Makefile,v 1.19 2026/10/16 07:29:38 wiz Exp $

DISTNAME=	jellyfish-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jellyfish/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/jpt/jellyfish
COMMENT=	Python library for doing approximate and phonetic matching of strings
LICENSE=	2-clause-bsd

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
