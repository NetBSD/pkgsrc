# $NetBSD: Makefile,v 1.67 2017/06/18 22:29:54 youri Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=		xfce4-panel-4.13.0
CATEGORIES=		x11
MASTER_SITES+=		http://archive.xfce.org/src/xfce/xfce4-panel/4.13/

HOMEPAGE=		http://docs.xfce.org/xfce/xfce4-panel/start
COMMENT=		Xfce panel

PKGCONFIG_OVERRIDE=	libxfce4panel/libxfce4panel-1.0.pc.in
PTHREAD_AUTO_VARS=	yes

PKG_SYSCONFSUBDIR=	xdg/xfce4/panel
EGDIR=			${XFCE4_EGBASE}/panel

CONF_FILES+=	${EGDIR}/default.xml ${PKG_SYSCONFDIR}/default.xml

.include "../../devel/libwnck3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
