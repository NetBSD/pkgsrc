# $NetBSD: Makefile,v 1.37 1999/11/21 16:49:11 frueauf Exp $
#

DISTNAME=	xscreensaver-3.21
CATEGORIES=	x11
MASTER_SITES=	http://www.jwz.org/xscreensaver/

MAINTAINER=	frueauf@netbsd.org
HOMEPAGE=	http://www.jwz.org/xscreensaver/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	Mesa-*:../../graphics/Mesa
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

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

.if (${OPSYS} == "NetBSD")
.if defined(KERBEROS)
CFLAGS+=	-I/usr/include/kerberosIV
CONFIGURE_ARGS+=--with-kerberos=yes
.endif
.endif

.include "../../mk/bsd.pkg.mk"
