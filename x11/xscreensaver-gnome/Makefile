# $NetBSD: Makefile,v 1.6 2001/11/01 09:41:15 jlam Exp $
#

PKGNAME=	${DISTNAME:S/-/-gnome-/}

COMMENT=	Screen saver and locker for the X window system (with GNOME support)

DEPENDS+=	control-center>=1.2.0:../../x11/controlcenter

CONFLICTS+=	xscreensaver-[0-9]*

PLIST_SRC=	${.CURDIR}/PLIST

.include "../../x11/xscreensaver/Makefile.common"
