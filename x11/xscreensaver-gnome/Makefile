# $NetBSD: Makefile,v 1.7 2002/02/09 21:12:57 wiz Exp $
#

PKGNAME=	${DISTNAME:S/-/-gnome-/}

COMMENT=	Screen saver and locker for the X window system (with GNOME support)

DEPENDS+=	control-center>=1.2.0:../../x11/controlcenter

CONFLICTS+=	xscreensaver-[0-9]*

CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/share/control-center/screensavers

PLIST_SRC=	${.CURDIR}/PLIST

.include "../../x11/xscreensaver/Makefile.common"
