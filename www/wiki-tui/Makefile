# $NetBSD: Makefile,v 1.23 2024/05/06 08:40:33 jperkin Exp $

DISTNAME=	wiki-tui-0.8.2
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=Builditluc/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://builditluc.github.io/wiki-tui/
COMMENT=	Simple and easy to use Wikipedia TUI
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	share/applications share/icons/hicolor/scalable/apps

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ncurses}/lib

post-install:
	${INSTALL_DATA} ${WRKSRC}/wiki-tui.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/hicolor/scalable/apps/wiki-tui.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
