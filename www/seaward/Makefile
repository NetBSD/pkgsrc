# $NetBSD: Makefile,v 1.6 2025/06/04 07:50:26 pin Exp $

DISTNAME=	seaward-1.1.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=M3nny/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/M3nny/seaward/
COMMENT=	Grep-like tool for the web
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
