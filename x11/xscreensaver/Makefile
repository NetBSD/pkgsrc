# $NetBSD: Makefile,v 1.13 1998/10/29 21:28:27 frueauf Exp $
#

DISTNAME=	xscreensaver-3.02
CATEGORIES=	x11
MASTER_SITES=	http://www.jwz.org/xscreensaver/

MAINTAINER=	frueauf@netbsd.org
HOMEPAGE=	http://www.jwz.org/xscreensaver/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	Xaw3d-1.5:../../x11/Xaw3d
DEPENDS+=	Mesa-3.0:../../graphics/Mesa

CONFLICTS=	xscreensaver-2.23 xscreensaver-2.24 xscreensaver-2.26 \
		xscreensaver-2.32 xscreensaver-2.33 xscreensaver-2.34 \
		xscreensaver-3.00

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-shadow --with-zippy=/usr/games/fortune \
		--enable-subdir=${PREFIX}/libexec/xscreensaver
CONFIGURE_ENV+=	INSTALL=/usr/bin/install

USE_X11=	yes
USE_MOTIF=	yes

.include "../../mk/bsd.pkg.mk"
