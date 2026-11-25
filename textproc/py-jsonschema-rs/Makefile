# $NetBSD: Makefile,v 1.3 2026/11/25 08:45:46 adam Exp $

DISTNAME=	jsonschema_rs-0.63.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonschema-rs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Stranger6667/jsonschema/tree/master/crates/jsonschema-py
COMMENT=	High-performance JSON Schema validator for Python
LICENSE=	mit

RUST_REQ=	1.85.0

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
