# $NetBSD: Makefile,v 1.78 2006/05/14 18:55:50 wiz Exp $

COMMENT=	Screen saver and locker for the X window system
PKGREVISION=	4

CONFLICTS+=	xscreensaver-gnome<4.14
# man/man1/barcode.1
CONFLICTS+=	barcode-[0-9]*

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--with-xml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

.include "options.mk"

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
