# $NetBSD: Makefile,v 1.4 2001/02/08 16:44:12 tron Exp $
#

PKGNAME=	${DISTNAME:S/-/-gnome-/}

DEPENDS+=	control-center>=1.2.0:../../x11/controlcenter

CONFLICTS+=	xscreensaver-[0-9]*

PLIST_SRC=	${.CURDIR}/pkg/PLIST

.include "../../x11/xscreensaver/Makefile.common"
