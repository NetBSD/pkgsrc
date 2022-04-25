# $NetBSD: Makefile,v 1.4 2022/04/25 19:05:34 pin Exp $

DISTNAME=	leftwm-0.3.0
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=leftwm/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://leftwm.org/
COMMENT=	Tiling window manager for adventurers
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/xsessions

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/leftwm ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/leftwm-check ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/leftwm-command ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/leftwm-state ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/leftwm-worker ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/leftwm/doc/leftwm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/leftwm.1
	${INSTALL_DATA} ${WRKSRC}/leftwm.desktop ${DESTDIR}${PREFIX}/share/xsessions

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "NetBSD" || ${X11_TYPE} == "modular"
DEPENDS+=	xrandr-[0-9]*:../../x11/xrandr
.endif

.include "../../lang/rust/cargo.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
