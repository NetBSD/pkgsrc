# $NetBSD: Makefile,v 1.3 2023/10/24 22:11:23 wiz Exp $

DISTNAME=	saturn-0.4.3
PKGNAME=	saturn-cli-0.4.3
PKGREVISION=	1
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
