# $NetBSD: Makefile,v 1.50 2018/11/12 03:53:15 ryoon Exp $

PKGREVISION= 8
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-notes-plugin-1.8.1
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-notes-plugin/1.8/

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-notes-plugin
COMMENT=	Xfce notes plugin

LDFLAGS.DragonFly=	-lm -lX11
LDFLAGS.SunOS+=		-lm -lX11

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
