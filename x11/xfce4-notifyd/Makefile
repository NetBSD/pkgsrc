# $NetBSD: Makefile,v 1.6 2017/06/18 23:11:26 youri Exp $
#

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-notifyd-0.3.6
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/apps/xfce4-notifyd/0.3/

HOMEPAGE=	http://goodies.xfce.org/projects/applications/xfce4-notifyd
COMMENT=	XFCE Notify daemon

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
