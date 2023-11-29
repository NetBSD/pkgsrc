# $NetBSD: Makefile,v 1.21 2023/11/29 13:43:22 pin Exp $

DISTNAME=	ripgrep-14.0.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=BurntSushi/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/BurntSushi/ripgrep/
COMMENT=	Line-oriented search tool
LICENSE=	unlicense

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pcre2}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.pcre2}/lib

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		pcre2

.include "../../lang/rust/cargo.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
