# $NetBSD: Makefile,v 1.5 1998/07/26 20:24:16 frueauf Exp $
#

DISTNAME=	xscreensaver-2.26
CATEGORIES=	x11
MASTER_SITES=	http://people.netscape.com/jwz/xscreensaver/

MAINTAINER=	frueauf@netbsd.org

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	Xaw3d-1.5:../../x11/Xaw3d
DEPENDS+=	Mesa-2.6:../../graphics/Mesa

CONFLICTS=	xscreensaver-2.23 xscreensaver-2.24

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-shadow --with-zippy=/usr/games/fortune \
		--enable-subdir=${PREFIX}/libexec/xscreensaver

USE_X11=	yes
USE_MOTIF=	yes

.include "../../mk/bsd.pkg.mk"
