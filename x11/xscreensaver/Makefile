# $NetBSD: Makefile,v 1.8 1998/09/30 20:04:06 tron Exp $
#

DISTNAME=	xscreensaver-2.26
CATEGORIES=	x11
MASTER_SITES=	http://people.netscape.com/jwz/xscreensaver/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.jwz.org/xscreensaver/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	Xaw3d-1.5:../../x11/Xaw3d
DEPENDS+=	Mesa-3.0:../../graphics/Mesa

CONFLICTS=	xscreensaver-2.23 xscreensaver-2.24

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-shadow --with-zippy=/usr/games/fortune \
		--enable-subdir=${PREFIX}/libexec/xscreensaver

USE_X11=	yes
USE_MOTIF=	yes

.include "../../mk/bsd.pkg.mk"
