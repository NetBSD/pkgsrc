# $NetBSD: Makefile,v 1.5 2024/03/09 21:54:02 pin Exp $

DISTNAME=	saturn-0.4.5
PKGNAME=	saturn-cli-0.4.5
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=erikh/}
GITHUB_PROJECT=	saturn
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/erikh/saturn/
COMMENT=	Calendar for CLI nerds
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
