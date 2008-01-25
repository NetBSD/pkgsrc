# $NetBSD: Makefile,v 1.39 2008/01/25 18:21:18 bjs Exp $

DISTNAME=	xterm-231
CATEGORIES=	x11
MASTER_SITES=	ftp://invisible-island.net/xterm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dickey.his.com/xterm/xterm.html
COMMENT=	Latest terminal emulator for the X Window System

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_DIRS+=	xdg-1.4
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+= --disable-imake --enable-narrowproto
.endif

.if exists(/usr/include/wchar.h)
CONFIGURE_ARGS+= --enable-wide-chars
.endif

.include "options.mk"

.if ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+= --with-setuid
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
###
### For detection of XKB bell extension.
###
BUILDLINK_DEPMETHOD.libxkbfile?=	build
.include "../../x11/libxkbfile/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
