# $NetBSD: Makefile,v 1.64 2004/01/23 21:50:52 jmmv Exp $
#

COMMENT=	Screen saver and locker for the X window system
PKGREVISION=	2

CONFLICTS+=	xscreensaver-gnome<4.14

.include "../../x11/xscreensaver/Makefile.common"

CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--with-xml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
