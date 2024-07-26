# $NetBSD: Makefile,v 1.4 2024/07/26 09:03:16 pin Exp $

DISTNAME=	xt-0.19.1
PKGNAME=	xt-rs-0.19.1
CATEGORIES=	textproc
MASTER_SITES=	https://static.crates.io/crates/xt/
EXTRACT_SUFX=	.crate

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/ahamlinman/xt/
COMMENT=	Translate between serialized data formats
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.70.0
USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
