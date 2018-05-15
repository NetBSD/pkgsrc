# $NetBSD: Makefile,v 1.11 2018/05/15 22:11:39 youri Exp $
#

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-notifyd-0.4.2
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/apps/xfce4-notifyd/0.4/

HOMEPAGE=	http://goodies.xfce.org/projects/applications/xfce4-notifyd
COMMENT=	XFCE Notify daemon

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
