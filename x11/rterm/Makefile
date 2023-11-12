# $NetBSD: Makefile,v 1.13 2023/11/12 13:24:30 wiz Exp $

DISTNAME=	rterm-0.0.8
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=mechpen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mechpen/rterm/
COMMENT=	Port of suckless terminal to rust
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${PREFIX}/lib
RUSTFLAGS+=	-C link-arg=-L${PREFIX}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${X11BASE}/lib
RUSTFLAGS+=	-C link-arg=-L${X11BASE}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.fontconfig}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.fontconfig}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rterm \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
