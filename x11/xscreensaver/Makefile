# $NetBSD: Makefile,v 1.20 1999/02/20 22:48:48 hubertf Exp $
#

DISTNAME=	xscreensaver-3.07
CATEGORIES=	x11
MASTER_SITES=	http://www.jwz.org/xscreensaver/

MAINTAINER=	frueauf@netbsd.org
HOMEPAGE=	http://www.jwz.org/xscreensaver/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	Xaw3d-1.5:../../x11/Xaw3d
DEPENDS+=	Mesa-3.0:../../graphics/Mesa

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-shadow --with-zippy=/usr/games/fortune \
		--enable-subdir=${PREFIX}/libexec/xscreensaver
CONFIGURE_ENV+=	INSTALL=/usr/bin/install

USE_X11BASE=	yes
USE_MOTIF=	yes

.include "../../mk/bsd.pkg.mk"
