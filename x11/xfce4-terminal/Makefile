# $NetBSD: Makefile,v 1.69 2022/06/04 00:18:34 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-terminal-1.0.4
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/apps/xfce4-terminal/1.0/

HOMEPAGE=	https://docs.xfce.org/apps/terminal/start
COMMENT=	Xfce terminal emulator

.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/vte3/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
