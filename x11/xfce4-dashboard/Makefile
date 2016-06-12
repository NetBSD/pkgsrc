# $NetBSD: Makefile,v 1.2 2016/06/12 18:47:37 youri Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfdashboard-0.6.0
PKGNAME=	xfce4-dashboard-0.6.0
CATEGORIES=	x11
MASTER_SITES+=	http://archive.xfce.org/src/apps/xfdashboard/0.6/

HOMEPAGE=	http://goodies.xfce.org/projects/applications/xfdashboard/start
COMMENT=	Maybe a Gnome shell like dashboard for Xfce

EGDIR=			${XFCE4_EGBASE}
PKG_SYSCONFSUBDIR=	xdg

CONF_FILES=		${EGDIR}/autostart/xfdashboard-autostart.desktop \
			${PKG_SYSCONFDIR}/autostart/xfdashboard-autostart.desktop

.include "../../devel/libwnck3/buildlink3.mk"
.include "../../devel/xfce4-conf/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
