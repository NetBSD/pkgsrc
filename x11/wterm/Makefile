# $NetBSD: Makefile,v 1.7 2000/02/19 19:42:55 rh Exp $
#

DISTNAME=	wterm-6.2.6
CATEGORIES=	x11
MASTER_SITES=	http://wm.current.nu/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://wm.current.nu/files.php\#wterm

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	windowmaker-*:../../x11/windowmaker

USE_X11BASE=	YES
GNU_CONFIGURE=	YES

CFLAGS+=	-I${LOCALBASE}/include

CONFIGURE_ARGS+= --enable-utmp --enable-wtmp --enable-xpm-background
CONFIGURE_ARGS+= --enable-menubar --enable-graphics --enable-next-scroll
CONFIGURE_ARGS+= --enable-half-shadow

post-install:
		${INSTALL_DATA} ${WRKSRC}/wterm.tiff \
			${PREFIX}/share/WindowMaker/Icons
		${INSTALL_DATA} ${WRKSRC}/wtermthai.tiff \
			${PREFIX}/share/WindowMaker/Icons

.include "../../mk/bsd.pkg.mk"
