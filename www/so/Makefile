# $NetBSD: Makefile,v 1.2 2021/06/30 11:33:37 pin Exp $

DISTNAME=	so-0.4.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=samtay/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/samtay/so/
COMMENT=	Terminal interface for Stack Overflow
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES=	c # rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
MAKE_ENV+=	RUSTFLAGS=${RUSTFLAGS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/so ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
