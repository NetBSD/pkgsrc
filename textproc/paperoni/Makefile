# $NetBSD: Makefile,v 1.5 2021/07/22 16:16:37 tnn Exp $

DISTNAME=	v0.5.0-alpha1
PKGNAME=	paperoni-0.5.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=hipstermojo/}
GITHUB_PROJECT=	paperoni
GITHUB_TAG=	v0.5.0-alpha1

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/hipstermojo/paperoni/
COMMENT=	Article extractor in Rust
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/paperoni ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
