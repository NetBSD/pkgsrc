# $NetBSD: Makefile,v 1.61 2003/12/13 00:45:27 wiz Exp $
#

COMMENT=	Screen saver and locker for the X window system

CONFLICTS+=	xscreensaver-gnome-[0-9]*
PKGREVISION=	2

.include "../../x11/xscreensaver/Makefile.common"

CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=        --with-gtk=${BUILDLINK_PREFIX.gtk2}
CONFIGURE_ARGS+=        --with-xml=${BUILDLINK_PREFIX.libxml2}

CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

.include "../../devel/libglade2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
