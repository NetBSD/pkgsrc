# $NetBSD: Makefile,v 1.29 1999/08/25 13:37:37 agc Exp $
#

DISTNAME=	xscreensaver-3.17
CATEGORIES=	x11
MASTER_SITES=	http://www.jwz.org/xscreensaver/

MAINTAINER=	frueauf@netbsd.org
HOMEPAGE=	http://www.jwz.org/xscreensaver/

DEPENDS=	xpm-3.4k:../../graphics/xpm	\
		Mesa-3.0:../../graphics/Mesa	\
		gtk+-1.2.2:../../x11/gtk

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-shadow --with-zippy=/usr/games/fortune \
		--enable-subdir=${PREFIX}/libexec/xscreensaver
CONFIGURE_ENV+=	INSTALL=/usr/bin/install

USE_X11BASE=	yes
USE_MOTIF=	yes
USE_PERL5=	yes
USE_XAW=	yes

.include "../../mk/bsd.prefs.mk"

XAW_TYPE?=	3d

.include "../../mk/bsd.pkg.mk"
