# $NetBSD: Makefile,v 1.30 1999/08/29 09:05:49 rh Exp $
#

DISTNAME=	xscreensaver-3.17
CATEGORIES=	x11
MASTER_SITES=	http://www.jwz.org/xscreensaver/

MAINTAINER=	frueauf@netbsd.org
HOMEPAGE=	http://www.jwz.org/xscreensaver/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	Mesa-3.0:../../graphics/Mesa
DEPENDS+=	gtk+-1.2.4:../../x11/gtk

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
