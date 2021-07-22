# $NetBSD: Makefile,v 1.17 2021/07/22 16:16:37 tnn Exp $

DISTNAME=	ripgrep-13.0.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=BurntSushi/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/BurntSushi/ripgrep/
COMMENT=	Line-oriented search tool
LICENSE=	unlicense

.include "cargo-depends.mk"

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pcre2}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.pcre2}/lib

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		pcre2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rg ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
