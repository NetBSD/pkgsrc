# $NetBSD: Makefile,v 1.61 2015/04/21 08:56:44 jperkin Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=		xfce4-panel-${XFCE4_VERSION}
CATEGORIES=		x11

HOMEPAGE=	http://docs.xfce.org/xfce/xfce4-panel/start
COMMENT=		Xfce panel

PKGCONFIG_OVERRIDE=	libxfce4panel/libxfce4panel-1.0.pc.in
PTHREAD_AUTO_VARS=	yes

PKG_SYSCONFSUBDIR=	xdg/xfce4/panel
EGDIR=			${XFCE4_EGBASE}/panel

CONF_FILES+=	${EGDIR}/default.xml ${PKG_SYSCONFDIR}/default.xml

.include "../../devel/libwnck/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
