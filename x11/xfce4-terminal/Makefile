# $NetBSD: Makefile,v 1.64 2021/12/08 16:07:17 adam Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-terminal-0.8.10
PKGREVISION=	2
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
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
