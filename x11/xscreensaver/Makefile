# $NetBSD: Makefile,v 1.47 2002/02/09 21:12:56 wiz Exp $
#

COMMENT=	Screen saver and locker for the X window system

CONFLICTS+=	xscreensaver-gnome-[0-9]*

CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

.include "../../x11/xscreensaver/Makefile.common"
