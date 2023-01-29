# $NetBSD: Makefile,v 1.9 2023/01/29 21:18:22 ryoon Exp $

DISTNAME=	rterm-0.0.7
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=mechpen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mechpen/rterm/
COMMENT=	Port of suckless terminal to rust
LICENSE=	unlicense

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libXft}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libXft}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rterm \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
