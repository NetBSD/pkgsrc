# $NetBSD: Makefile,v 1.43 2018/03/12 11:18:00 wiz Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-terminal-0.8.5.1
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/apps/xfce4-terminal/0.8/

HOMEPAGE=	http://docs.xfce.org/apps/terminal/start
COMMENT=	Xfce terminal emulator

MAKE_JOBS_SAFE=	no

.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/vte3/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
