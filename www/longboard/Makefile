# $NetBSD: Makefile,v 1.2 2021/07/22 16:16:37 tnn Exp $

DISTNAME=	longboard-0.0.7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=jbr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/jbr/longboard/
COMMENT=	Longboard: The easy way to surf
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/longboard ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
