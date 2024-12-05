# $NetBSD: Makefile,v 1.25 2024/12/05 07:02:09 pin Exp $

DISTNAME=	wiki-tui-0.9.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=Builditluc/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://builditluc.github.io/wiki-tui/
COMMENT=	Simple and easy to use Wikipedia TUI
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.76.0
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	share/applications share/icons/hicolor/scalable/apps

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

post-install:
	${INSTALL_DATA} ${WRKSRC}/wiki-tui.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/hicolor/scalable/apps/wiki-tui.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
