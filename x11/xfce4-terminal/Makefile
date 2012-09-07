# $NetBSD: Makefile,v 1.23 2012/09/07 19:17:55 adam Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.4.2

DISTNAME=	Terminal-${XFCE4_VERSION}
PKGNAME=	xfce4-terminal-${XFCE4_VERSION}
PKGREVISION=	10
CATEGORIES=	x11
COMMENT=	Xfce terminal emulator

MASTER_SITES=	http://www.xfce.org/archive/src/apps/terminal/0.4/

MAKE_JOBS_SAFE=	no

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
