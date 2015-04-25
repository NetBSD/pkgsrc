# $NetBSD: Makefile,v 1.41 2015/04/25 14:25:24 tnn Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-notes-plugin-1.7.7
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-notes-plugin/1.7/

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-notes-plugin
COMMENT=	Xfce notes plugin

LDFLAGS.DragonFly=	-lm -lX11
LDFLAGS.SunOS+=		-lm -lX11

CONF_FILES=	${XFCE4_EGBASE}/autostart/xfce4-notes-autostart.desktop \
		${PKG_SYSCONFDIR}/examples/autostart/xfce4-notes-autostart.desktop

MAKE_DIRS+=	${XFCE4_EGBASE}/autostart

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
