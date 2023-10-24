# $NetBSD: Makefile,v 1.10 2023/10/24 22:11:19 wiz Exp $

DISTNAME=	paperoni-v0.6.1-alpha1
PKGNAME=	paperoni-0.6.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=hipstermojo/}
GITHUB_PROJECT=	paperoni
GITHUB_TAG=	v0.6.1-alpha1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hipstermojo/paperoni/
COMMENT=	Article extractor in Rust
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/paperoni \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
