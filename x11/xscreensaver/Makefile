# $NetBSD: Makefile,v 1.48.2.1 2002/06/30 06:24:48 jlam Exp $
#

COMMENT=	Screen saver and locker for the X window system

CONFLICTS+=	xscreensaver-gnome-[0-9]*

USE_BUILDLINK2=	yes

.include "../../x11/xscreensaver/Makefile.common"

CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

.include "../../mk/bsd.pkg.mk"
