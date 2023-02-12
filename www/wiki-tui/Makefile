# $NetBSD: Makefile,v 1.14 2023/02/12 19:04:29 pin Exp $

DISTNAME=	wiki-tui-0.6.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=Builditluc/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://builditluc.github.io/wiki-tui/
COMMENT=	Simple and easy to use Wikipedia TUI
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config
USE_NCURSES=	yes #NCURSES_MOUSE_VERSION

INSTALLATION_DIRS=	bin share/applications

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ncursesw}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/wiki-tui \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/wiki-tui.desktop \
		${DESTDIR}${PREFIX}/share/applications

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
