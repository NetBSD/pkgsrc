# $NetBSD: Makefile,v 1.6 1999/10/25 15:09:46 hubertf Exp $
#

DISTNAME=	wterm-6.2.6
CATEGORIES=	x11
MASTER_SITES=	http://wm.current.nu/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://wm.current.nu/files.html\#wterm

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	windowmaker-*:../../x11/windowmaker

USE_X11=	YES
GNU_CONFIGURE=	YES

CFLAGS+=	-I${PREFIX}/include
PLIST_SUBST+=	PREFIX=${PREFIX} \
		X11BASE=${X11BASE}

CONFIGURE_ARGS+= --enable-utmp --enable-wtmp --enable-xpm-background --enable-menubar --enable-graphics --enable-next-scroll --enable-half-shadow

post-install:
		${INSTALL_DATA} ${WRKSRC}/wterm.tiff ${X11BASE}/share/WindowMaker/Icons
		${INSTALL_DATA} ${WRKSRC}/wtermthai.tiff ${X11BASE}/share/WindowMaker/Icons

.include "../../mk/bsd.pkg.mk"
