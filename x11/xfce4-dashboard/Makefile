# $NetBSD: Makefile,v 1.23 2022/08/11 05:09:34 gutteridge Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.9.2
DISTNAME=	xfdashboard-${VERSION}
PKGNAME=	xfce4-dashboard-${VERSION}
CATEGORIES=	x11
MASTER_SITES+=	https://archive.xfce.org/src/apps/xfdashboard/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/applications/xfdashboard/start
COMMENT=	Maybe a Gnome shell like dashboard for Xfce

EGDIR=			${XFCE4_EGBASE}
PKG_SYSCONFSUBDIR=	xdg

CONF_FILES=		${EGDIR}/autostart/org.xfce.xfdashboard-autostart.desktop \
			${PKG_SYSCONFDIR}/autostart/org.xfce.xfdashboard-autostart.desktop

.include "../../devel/libwnck3/buildlink3.mk"
.include "../../devel/xfce4-conf/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
