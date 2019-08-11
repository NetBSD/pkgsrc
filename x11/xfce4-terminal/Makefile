# $NetBSD: Makefile,v 1.53 2019/08/11 13:25:20 wiz Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-terminal-0.8.8
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/apps/xfce4-terminal/0.8/

HOMEPAGE=	https://docs.xfce.org/apps/terminal/start
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
