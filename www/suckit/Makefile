# $NetBSD: Makefile,v 1.6 2023/10/24 22:11:35 wiz Exp $

DISTNAME=	suckit-0.2.0
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=Skallwar/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Skallwar/suckit/
COMMENT=	Suck the InTernet
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

CHECK_PORTABILITY_SKIP+=	tests/local_server_setup.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/suckit \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
