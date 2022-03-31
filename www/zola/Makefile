# $NetBSD: Makefile,v 1.9 2022/03/31 15:29:29 nikita Exp $

DISTNAME=	zola-0.15.3
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=getzola/}
GITHUB_PROJECT=	zola
GITHUB_TAG=	v0.15.3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.getzola.org/
COMMENT=	Static website generator
LICENSE=	mit
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=		-C link-arg=-L${BUILDLINK_PREFIX.SDL2}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/zola ${DESTDIR}${PREFIX}/bin

.include "../../devel/SDL2/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
