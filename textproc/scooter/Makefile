# $NetBSD: Makefile,v 1.4 2025/10/07 10:43:42 pin Exp $

DISTNAME=	scooter-0.8.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=thomasschafer/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thomasschafer/scooter/
COMMENT=	Interactive find and replace in the terminal
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.90.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.90.0 on amd64
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/scooter \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
