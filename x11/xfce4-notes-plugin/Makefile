# $NetBSD: Makefile,v 1.84 2026/01/27 08:41:07 wiz Exp $

PKGREVISION= 6
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-notes-plugin-1.11.2
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-notes-plugin/1.11/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-notes-plugin
COMMENT=	Xfce notes plugin

BUILD_DEFS+=		PKG_SYSCONFBASE

LDFLAGS.DragonFly=	-lm -lX11
LDFLAGS.SunOS+=		-lm -lX11

PKG_SYSCONFSUBDIR=	xdg

CONF_FILES=	${XFCE4_EGBASE}/autostart/xfce4-notes-autostart.desktop \
		${PKG_SYSCONFDIR}/autostart/xfce4-notes-autostart.desktop

MAKE_DIRS+=	${XFCE4_EGBASE}/autostart \
		${PKG_SYSCONFDIR}/autostart

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/xfce4-conf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtksourceview4/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
