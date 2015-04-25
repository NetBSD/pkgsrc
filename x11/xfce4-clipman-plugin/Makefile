# $NetBSD: Makefile,v 1.38 2015/04/25 14:25:24 tnn Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-clipman-plugin-1.2.6
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-clipman-plugin/1.2/

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-clipman-plugin
COMMENT=	Xfce clipboard plugin

CONF_FILES=	${XFCE4_EGBASE}/autostart/xfce4-clipman-plugin-autostart.desktop	\
		${PKG_SYSCONFDIR}/autostart/xfce4-clipman-plugin-autostart.desktop	\
		${XFCE4_EGBASE}/panel/xfce4-clipman-actions.xml	\
		${PKG_SYSCONFDIR}/panel/xfce4-clipman-actions.xml

MAKE_DIRS+=	${XFCE4_EGBASE}/autostart \
		${XFCE4_EGBASE}/panel

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
