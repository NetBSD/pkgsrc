# $NetBSD: Makefile,v 1.9 2002/03/19 15:34:33 wiz Exp $
#

PKGNAME=	${DISTNAME:S/-/-gnome-/}

COMMENT=	Screen saver and locker for the X window system (with GNOME support)

DEPENDS+=	control-center>=1.4.0.1nb1:../../x11/controlcenter

CONFLICTS+=	xscreensaver-[0-9]*

CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/share/control-center/screensavers

PLIST_SRC=	${.CURDIR}/PLIST

.include "../../x11/xscreensaver/Makefile.common"
