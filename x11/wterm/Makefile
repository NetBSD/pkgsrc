# $NetBSD: Makefile,v 1.5 1999/09/21 18:18:50 tron Exp $
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

CONFIGURE_ARGS+= --enable-utmp --enable-wtmp --enable-xpm-background --enable-menubar --enable-graphics --enable-next-scroll --enable-half-shadow

.include "../../mk/bsd.pkg.mk"
