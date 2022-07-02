# $NetBSD: Makefile,v 1.25 2022/07/02 16:53:41 ryoon Exp $

DISTNAME=	lxqt-panel-1.1.0
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-panel/
COMMENT=	Desktop panel
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DSYSSTAT_PLUGIN=No

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Linux"
CMAKE_ARGS+=	-DCPULOAD_PLUGIN=No
CMAKE_ARGS+=	-DMOUNT_PLUGIN=No
CMAKE_ARGS+=	-DSENSORS_PLUGIN=No
CMAKE_ARGS+=	-DNETWORKMONITOR_PLUGIN=No
CMAKE_ARGS+=	-DVOLUME_USE_ALSA=No
.endif

MENU_CONF=		share/examples/menus
AUTOSTART_CONF=		share/examples/autostart
PANEL_CONF=		share/examples/lxqt
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS=		${PKG_SYSCONFDIR}/menus
MAKE_DIRS+=		${PKG_SYSCONFDIR}/autostart
MAKE_DIRS+=		${PKG_SYSCONFDIR}/lxqt

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	plugin-directorymenu/directorymenuconfiguration.cpp
SUBST_FILES.prefix+=	plugin-mainmenu/lxqtmainmenuconfiguration.cpp
SUBST_FILES.prefix+=	plugin-kbindicator/src/x11/kbdlayout.cpp
SUBST_SED.prefix=	-e 's,/etc/xdg,${PKG_SYSCONFDIR},g'
SUBST_SED.prefix+=	-e 's,/usr/bin,${PREFIX}/bin,g'
SUBST_SED.prefix+=	-e 's,/usr/share,${PREFIX}/share,g'

CONF_FILES=	${MENU_CONF}/lxqt-applications.menu \
		${PKG_SYSCONFDIR}/menus/lxqt-applications.menu
CONF_FILES+=	${MENU_CONF}/lxqt-applications-compact.menu \
		${PKG_SYSCONFDIR}/menus/lxqt-applications-compact.menu
CONF_FILES+=	${MENU_CONF}/lxqt-applications-simple.menu \
		${PKG_SYSCONFDIR}/menus/lxqt-applications-simple.menu
CONF_FILES+=	${AUTOSTART_CONF}/lxqt-panel.desktop \
		${PKG_SYSCONFDIR}/autostart/lxqt-panel.desktop
CONF_FILES+=	${PANEL_CONF}/panel.conf \
		${PKG_SYSCONFDIR}/lxqt/panel.conf

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools>=0.11.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools
DEPENDS+=	lxmenu-data-[0-9]*:../../sysutils/lxmenu-data

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../devel/libdbusmenu-qt5/buildlink3.mk"
.include "../../x11/lxqt-globalkeys/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../sysutils/solid/buildlink3.mk"
.include "../../x11/kwindowsystem/buildlink3.mk"
.include "../../x11/kguiaddons/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
