# $NetBSD: Makefile,v 1.13 2026/08/30 08:11:25 he Exp $

DISTNAME=	crates-io-cli-4.0.3
PKGREVISION=	7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=Byron/}
GITHUB_TAG=	230e5c63e14ffe8dfc66cdc0d6db730f37d08224

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Byron/crates-io-cli/
COMMENT=	Interact with crates.io from the command-line
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/crates-io-cli-230e5c63e14ffe8dfc66cdc0d6db730f37d08224	

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
