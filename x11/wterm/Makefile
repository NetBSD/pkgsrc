# $NetBSD: Makefile,v 1.17 2001/11/01 09:43:39 tron Exp $

DISTNAME=	wterm-6.2.9
CATEGORIES=	x11
MASTER_SITES=	http://largo.windowmaker.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://largo.windowmaker.org/files.php\#wterm
COMMENT=	NeXTStep(tm) style X11 terminal emulator for WindowMaker

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
# some /usr/X11R6/lib references sneak in
# USE_BUILDLINK_ONLY=	YES

CONFIGURE_ARGS+= --enable-utmp --enable-wtmp --enable-xpm-background
CONFIGURE_ARGS+= --enable-menubar --enable-graphics --enable-next-scroll
CONFIGURE_ARGS+= --enable-half-shadow
CONFIGURE_ARGS+= --with-xpm-library=${PREFIX}

post-install:
	${CHMOD} 4755 ${PREFIX}/bin/wterm
	${INSTALL_DATA} ${WRKSRC}/wterm.tiff \
		${PREFIX}/share/WindowMaker/Icons
	${INSTALL_DATA} ${WRKSRC}/wtermthai.tiff \
		${PREFIX}/share/WindowMaker/Icons

.include "../../wm/windowmaker/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
