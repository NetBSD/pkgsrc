# $NetBSD: Makefile,v 1.10 2026/01/12 11:56:36 pin Exp $

DISTNAME=	xt-0.20.0
PKGNAME=	xt-rs-0.20.0
CATEGORIES=	textproc
MASTER_SITES=	https://static.crates.io/crates/xt/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ahamlinman/xt/
COMMENT=	Translate between serialized data formats
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.85.0
USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
