# $NetBSD: Makefile,v 1.27 2004/10/03 00:18:39 tv Exp $

DISTNAME=	wterm-6.2.9
PKGREVISION=	4
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://largo.windowmaker.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://largo.windowmaker.org/files.php\#wterm
COMMENT=	NeXTStep(tm) style X11 terminal emulator for WindowMaker

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_BUILDLINK3=	YES

CONFIGURE_ARGS+= --enable-utmp --enable-wtmp
CONFIGURE_ARGS+= --enable-xpm-background --enable-transparency
CONFIGURE_ARGS+= --enable-menubar --enable-graphics --enable-next-scroll
CONFIGURE_ARGS+= --enable-half-shadow
CONFIGURE_ARGS+= --with-xpm-library=${BUILDLINK_PREFIX.xpm}

post-install:
	${CHMOD} 4755 ${PREFIX}/bin/wterm
	${INSTALL_DATA} ${WRKSRC}/wterm.tiff \
		${PREFIX}/share/WindowMaker/Icons
	${INSTALL_DATA} ${WRKSRC}/wtermthai.tiff \
		${PREFIX}/share/WindowMaker/Icons

.include "../../wm/windowmaker/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
