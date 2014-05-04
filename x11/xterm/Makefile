# $NetBSD: Makefile,v 1.88 2014/05/04 16:48:36 wiz Exp $

DISTNAME=	xterm-304
CATEGORIES=	x11
MASTER_SITES=	ftp://invisible-island.net/xterm/ \
		http://www.sfr-fresh.com/unix/misc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dickey.his.com/xterm/xterm.html
COMMENT=	Latest terminal emulator for the X Window System
LICENSE=	x11

GNU_CONFIGURE=		yes
USE_TOOLS+=		tbl pkg-config

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

CONFIGURE_ARGS+=	--enable-88-color
CONFIGURE_ARGS+=	--enable-256-color
CONFIGURE_ARGS+=	--enable-paste64
CONFIGURE_ARGS+=	--enable-readline-mouse

CONFIGURE_ARGS.standard=# empty
CONFIGURE_ARGS.3d=	--with-Xaw3d
CONFIGURE_ARGS.xpm=	--with-Xaw3d
CONFIGURE_ARGS.neXtaw=	--with-neXtaw
CONFIGURE_ARGS+=	${${CONFIGURE_ARGS.${XAW_TYPE}}:L}

INSTALLATION_DIRS=	share/applications

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--disable-imake
CONFIGURE_ARGS+=	--enable-narrowproto
.endif

.if exists(/usr/include/wchar.h)
CONFIGURE_ARGS+=	--enable-wide-chars
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
###
### For detection of XKB bell extension.
###
BUILDLINK_DEPMETHOD.libxkbfile?=	build
.include "../../x11/libxkbfile/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/xterm.desktop \
		${DESTDIR}${PREFIX}/share/applications && \
	${INSTALL_DATA} ${WRKSRC}/uxterm.desktop \
		${DESTDIR}${PREFIX}/share/applications
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && tbl xterm.1 \
		> xterm.1.tbl && mv xterm.1.tbl xterm.1

.include "options.mk"

.include "../../mk/termcap.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
