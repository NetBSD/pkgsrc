# $NetBSD: Makefile,v 1.6 2022/01/13 13:18:42 pin Exp $

DISTNAME=	wiki-tui-0.4.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=Builditluc/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Builditluc/wiki-tui/
COMMENT=	Simple and easy to use Wikipedia TUI
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config
USE_NCURSES=	yes #NCURSES_MOUSE_VERSION

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ncursesw}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/wiki-tui ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
