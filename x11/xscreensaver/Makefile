# $NetBSD: Makefile,v 1.50 2002/09/21 22:47:11 jlam Exp $
#

COMMENT=	Screen saver and locker for the X window system

CONFLICTS+=	xscreensaver-gnome-[0-9]*

.include "../../x11/xscreensaver/Makefile.common"

CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

.include "../../mk/bsd.pkg.mk"
