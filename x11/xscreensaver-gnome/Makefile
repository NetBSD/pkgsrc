# $NetBSD: Makefile,v 1.10 2002/04/09 22:50:03 jlam Exp $
#

PKGNAME=	${DISTNAME:S/-/-gnome-/}
COMMENT=	Screen saver and locker for the X window system (with GNOME support)

BUILDLINK_DEPENDS.control-center=	control-center>=1.4.0.1nb1

CONFLICTS+=		xscreensaver-[0-9]*

USE_BUILDLINK_ONLY=	yes

.include "../../x11/xscreensaver/Makefile.common"

CONFIGURE_ARGS+=	--with-gnome=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/share/control-center/screensavers

PLIST_SRC=	${.CURDIR}/PLIST

.include "../../x11/controlcenter/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
