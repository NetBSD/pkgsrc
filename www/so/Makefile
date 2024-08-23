# $NetBSD: Makefile,v 1.10 2024/08/23 15:55:23 pin Exp $

DISTNAME=	so-0.4.10
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=samtay/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/samtay/so/
COMMENT=	Terminal interface for Stack Overflow
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.79.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.79.0 on amd64
#INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

#do-install:
#	${INSTALL_PROGRAM} ${WRKSRC}/target/release/so \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
