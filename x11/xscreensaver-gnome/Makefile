# $NetBSD: Makefile,v 1.8 2002/03/13 17:38:05 fredb Exp $
#

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	1

COMMENT=	Screen saver and locker for the X window system (with GNOME support)

DEPENDS+=	control-center>=1.4.0.1nb1:../../x11/controlcenter

CONFLICTS+=	xscreensaver-[0-9]*

CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/share/control-center/screensavers

PLIST_SRC=	${.CURDIR}/PLIST

.include "../../x11/xscreensaver/Makefile.common"
