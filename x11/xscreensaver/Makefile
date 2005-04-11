# $NetBSD: Makefile,v 1.70 2005/04/11 21:48:16 tv Exp $

COMMENT=	Screen saver and locker for the X window system

CONFLICTS+=	xscreensaver-gnome<4.14
# man/man1/barcode.1
CONFLICTS+=	barcode-[0-9]*


.include "Makefile.common"

CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--with-xml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
