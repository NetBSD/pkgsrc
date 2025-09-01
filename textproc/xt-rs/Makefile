# $NetBSD: Makefile,v 1.9 2025/09/01 09:40:48 pin Exp $

DISTNAME=	xt-0.19.5
PKGNAME=	xt-rs-0.19.5
CATEGORIES=	textproc
MASTER_SITES=	https://static.crates.io/crates/xt/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ahamlinman/xt/
COMMENT=	Translate between serialized data formats
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.70.0
USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
