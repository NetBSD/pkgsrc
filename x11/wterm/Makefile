# $NetBSD: Makefile,v 1.19.2.1 2002/06/30 06:24:47 jlam Exp $

DISTNAME=	wterm-6.2.9
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://largo.windowmaker.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://largo.windowmaker.org/files.php\#wterm
COMMENT=	NeXTStep(tm) style X11 terminal emulator for WindowMaker

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_BUILDLINK2=	YES

CONFIGURE_ARGS+= --enable-utmp --enable-wtmp --enable-xpm-background
CONFIGURE_ARGS+= --enable-menubar --enable-graphics --enable-next-scroll
CONFIGURE_ARGS+= --enable-half-shadow
CONFIGURE_ARGS+= --with-xpm-library=${BUILDLINK_PREFIX.xpm}

post-install:
	${CHMOD} 4755 ${PREFIX}/bin/wterm
	${INSTALL_DATA} ${WRKSRC}/wterm.tiff \
		${PREFIX}/share/WindowMaker/Icons
	${INSTALL_DATA} ${WRKSRC}/wtermthai.tiff \
		${PREFIX}/share/WindowMaker/Icons

.include "../../wm/windowmaker/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
