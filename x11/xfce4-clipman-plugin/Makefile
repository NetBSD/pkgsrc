# $NetBSD: Makefile,v 1.73 2024/03/03 17:58:54 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	1.6.6
DISTNAME=	xfce4-clipman-plugin-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-clipman-plugin/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-clipman-plugin
COMMENT=	Xfce clipboard plugin

# Will otherwise potentially pick up Wayland libraries in the environment.
# Not ready for use with current state of Xfce in pkgsrc.
CONFIGURE_ARGS+=	--disable-wayland

PKG_SYSCONFSUBDIR=	xdg
CONF_FILES=		${XFCE4_EGBASE}/autostart/xfce4-clipman-plugin-autostart.desktop \
			${PKG_SYSCONFDIR}/autostart/xfce4-clipman-plugin-autostart.desktop \
			${XFCE4_EGBASE}/panel/xfce4-clipman-actions.xml \
			${PKG_SYSCONFDIR}/xfce4/panel/xfce4-clipman-actions.xml

MAKE_DIRS+=	${XFCE4_EGBASE}/autostart \
		${XFCE4_EGBASE}/panel

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
