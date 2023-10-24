# $NetBSD: Makefile,v 1.6 2023/10/24 22:11:25 wiz Exp $

DISTNAME=	cratuity-0.1.5
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=TheMayoras/}
GITHUB_PROJECT=	cratuity
GITHUB_TAG=	2d2b122ce39506563be21e1918b629fbb313ec15

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TheMayoras/cratuity/
COMMENT=	TUI for quickly searching crates.io
# Unclear license situation. While the project's Cargo.toml file still states
# gnu-gpl-v3, the projects github states gnu-agpl-v3.
# Opt to use the most restrictive here.
LICENSE=	gnu-agpl-v3

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		browser

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cratuity ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
