# $NetBSD: Makefile,v 1.4 1999/07/19 22:55:48 dante Exp $
#

DISTNAME=	wterm-6.2.6
CATEGORIES=	x11
MASTER_SITES=	http://wm.current.nu/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://wm.current.nu/files.html\#wterm

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	windowmaker-0.60.0:../../x11/windowmaker

USE_X11=	YES
GNU_CONFIGURE=	YES

CFLAGS+=	-I${PREFIX}/include

CONFIGURE_ARGS+= --enable-utmp --enable-wtmp --enable-xpm-background --enable-menubar --enable-graphics --enable-next-scroll --enable-half-shadow

.include "../../mk/bsd.pkg.mk"
