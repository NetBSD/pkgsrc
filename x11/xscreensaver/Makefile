# $NetBSD: Makefile,v 1.27 1999/07/02 15:23:12 frueauf Exp $
#

DISTNAME=	xscreensaver-3.16
CATEGORIES=	x11
MASTER_SITES=	http://www.jwz.org/xscreensaver/

MAINTAINER=	frueauf@netbsd.org
HOMEPAGE=	http://www.jwz.org/xscreensaver/

DEPENDS=	xpm-3.4k:../../graphics/xpm	\
		Xaw3d-1.5:../../x11/Xaw3d	\
		Mesa-3.0:../../graphics/Mesa	\
		gtk+-1.2.2:../../x11/gtk

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-shadow --with-zippy=/usr/games/fortune \
		--enable-subdir=${PREFIX}/libexec/xscreensaver
CONFIGURE_ENV+=	INSTALL=/usr/bin/install

USE_X11BASE=	yes
USE_MOTIF=	yes
USE_PERL5=	yes

.include "../../mk/bsd.pkg.mk"
