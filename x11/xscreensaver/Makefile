# $NetBSD: Makefile,v 1.65 2004/02/01 10:48:46 jlam Exp $

COMMENT=	Screen saver and locker for the X window system
PKGREVISION=	2

CONFLICTS+=	xscreensaver-gnome<4.14

USE_BUILDLINK3=	yes

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--with-xml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
