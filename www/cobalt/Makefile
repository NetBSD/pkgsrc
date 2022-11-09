# $NetBSD: Makefile,v 1.1 2022/11/09 13:32:49 nikita Exp $

DISTNAME=	cobalt-0.18.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=cobalt-org/}
GITHUB_PROJECT=	cobalt.rs
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cobalt-org/cobalt.rs/
COMMENT=	Static website generator
LICENSE=	mit

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake pkg-config

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libsass}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cobalt ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../www/libsass/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
