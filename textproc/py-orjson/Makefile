# $NetBSD: Makefile,v 1.27 2026/04/01 05:56:06 adam Exp $

DISTNAME=	orjson-3.11.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/orjson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ijl/orjson
COMMENT=	Fast, correct Python JSON library
LICENSE=	apache-2.0 AND mit AND mpl-2.0

RUST_REQ=	1.89.0

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
