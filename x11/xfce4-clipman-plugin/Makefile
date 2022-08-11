# $NetBSD: Makefile,v 1.64 2022/08/11 05:09:34 gutteridge Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	1.6.2
DISTNAME=	xfce4-clipman-plugin-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-clipman-plugin/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-clipman-plugin
COMMENT=	Xfce clipboard plugin

PKG_SYSCONFSUBDIR=	xdg
CONF_FILES=		${XFCE4_EGBASE}/autostart/xfce4-clipman-plugin-autostart.desktop	\
			${PKG_SYSCONFDIR}/autostart/xfce4-clipman-plugin-autostart.desktop	\
			${XFCE4_EGBASE}/panel/xfce4-clipman-actions.xml	\
			${PKG_SYSCONFDIR}/xfce4/panel/xfce4-clipman-actions.xml

MAKE_DIRS+=	${XFCE4_EGBASE}/autostart \
		${XFCE4_EGBASE}/panel

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
