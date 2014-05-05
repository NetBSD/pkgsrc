# $NetBSD: Makefile,v 1.60 2014/05/05 00:48:37 ryoon Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

PKGREVISION=		22

XFCE4_VERSION=		4.6.2

DISTNAME=		xfce4-panel-${XFCE4_VERSION}
CATEGORIES=		x11
COMMENT=		Xfce panel

MASTER_SITES+=		http://archive.xfce.org/src/xfce/xfce4-panel/4.6/

PKGCONFIG_OVERRIDE=	libxfce4panel/libxfce4panel-1.0.pc.in
PTHREAD_AUTO_VARS=	yes

PKG_SYSCONFSUBDIR=	xdg/xfce4/panel
EGDIR=			${XFCE4_EGBASE}/panel

MAKE_DIRS+=	${PREFIX}/include/xfce4 ${PREFIX}/lib/xfce4
MAKE_DIRS+=	${XFCE4_EGBASE:Q} ${PREFIX}/share/xfce4
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc ${PREFIX}/share/xfce4/doc/C
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/C/images
OWN_DIRS+=	${PKG_SYSCONFDIR}
OWN_DIRS+=	${PREFIX}/share/xfce4/panel-plugins
# The following are not used in this pkg, but here is a good place to rmdir them
MAKE_DIRS+=	${PREFIX}/libexec/xfce4
MAKE_DIRS+=	${PREFIX}/libexec/xfce4/panel-plugins

.for f in clock-14.rc launcher-10.rc launcher-7.rc launcher-8.rc launcher-9.rc \
	panels.xml systray-4.rc xfce4-menu-5.rc
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
