# $NetBSD: Makefile,v 1.2 1998/07/04 05:53:33 mycroft Exp $
#

DISTNAME=	xscreensaver-2.23
CATEGORIES=	x11
MASTER_SITES=	http://people.netscape.com/jwz/xscreensaver/

MAINTAINER=	packages@netbsd.org

DEPENDS+=	xpm-3.4j:../../graphics/xpm
DEPENDS+=	Xaw3d-1.5:../../x11/Xaw3d
DEPENDS+=	Mesa-2.6:../../graphics/Mesa

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-shadow --with-zippy=/usr/games/fortune

USE_X11=	yes
USE_MOTIF=	yes

.include "../../mk/bsd.pkg.mk"
