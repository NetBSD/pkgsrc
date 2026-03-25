# $NetBSD: Makefile,v 1.124 2026/03/25 22:51:24 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=		xfce4-panel-4.20.7
CATEGORIES=		x11
MASTER_SITES+=		https://archive.xfce.org/src/xfce/xfce4-panel/${PKGVERSION_NOREV:R}/

HOMEPAGE=		https://docs.xfce.org/xfce/xfce4-panel/start
COMMENT=		Xfce panel

TOOL_DEPENDS+=		xfce4-dev-tools-[0-9]*:../../devel/xfce4-dev-tools

USE_TOOLS+=		gdbus-codegen
REPLACE_PYTHON+=	xdt-gen-visibility

PKGCONFIG_OVERRIDE=	libxfce4panel/libxfce4panel-2.0.pc.in
PTHREAD_AUTO_VARS=	yes

PKG_SYSCONFSUBDIR=	xdg/xfce4/panel
EGDIR=			${XFCE4_EGBASE}/panel

CONFIGURE_ARGS+=	--enable-x11

CONF_FILES+=	${EGDIR}/default.xml ${PKG_SYSCONFDIR}/default.xml

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/libdbusmenu-gtk3/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxfce4windowing+=       libxfce4windowing>=4.20.1
.include "../../x11/libxfce4windowing/buildlink3.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
