# $NetBSD: Makefile,v 1.7 2024/10/17 07:04:23 pin Exp $

DISTNAME=	crates-io-cli-4.0.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=Byron/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Byron/crates-io-cli/
COMMENT=	Interact with crates.io from the command-line
LICENSE=	mit

SITES.curl-sys-0.4.77+curl-8.10.1.crate=	https://static.crates.io/crates/curl-sys/

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/crates \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
