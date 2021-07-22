# $NetBSD: Makefile,v 1.2 2021/07/22 16:16:37 tnn Exp $

DISTNAME=	cratuity-0.1.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=TheMayoras/}
GITHUB_PROJECT=	cratuity
GITHUB_TAG=	4d532ea5fc7db34799cde52c862ba2950748b6b2

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/TheMayoras/cratuity/
COMMENT=	TUI for quickly searching crates.io
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		no-copy

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cratuity ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
