# $NetBSD: Makefile,v 1.11 2002/08/29 09:51:09 jlam Exp $
#

PKGNAME=	${DISTNAME:S/-/-gnome-/}
COMMENT=	Screen saver and locker for the X window system (with GNOME support)

CONFLICTS+=	xscreensaver-[0-9]*

USE_BUILDLINK2=	yes
USE_X11=	yes

.include "../../x11/xscreensaver/Makefile.common"

CONFIGURE_ARGS+=	--with-gnome=${BUILDLINK_PREFIX.gnome-libs}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/share/control-center/screensavers

PLIST_SRC=	${.CURDIR}/PLIST

.include "../../x11/controlcenter/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
