# $NetBSD: Makefile,v 1.48 2002/04/09 22:50:02 jlam Exp $
#

COMMENT=	Screen saver and locker for the X window system

CONFLICTS+=	xscreensaver-gnome-[0-9]*

USE_BUILDLINK_ONLY=	yes

.include "../../x11/xscreensaver/Makefile.common"

CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
