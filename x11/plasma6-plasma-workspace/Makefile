# $NetBSD: Makefile,v 1.1 2026/05/04 11:18:46 markd Exp $

DISTNAME=	plasma-workspace-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	KDE Plasma Workspace
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/plasma6.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools
DEPENDS+=	plasma6-kwin-x11>=${PLASMAVER}:../../x11/plasma6-kwin-x11
DEPENDS+=	kf6-kded>=6.18.0:../../x11/kf6-kded
DEPENDS+=	kio-extras>=25.08.3:../../devel/kio-extras

USE_TOOLS+=	msgmerge pkg-config

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF
#CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug

CHECK_INTERPRETER_SKIP+=	share/kconf_update/*

# generation of ksmserver.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/*/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/*/*/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg+=	gmenu-dbusmenu-proxy/CMakeLists.txt
SUBST_FILES.xdg+=	libnotificationmanager/CMakeLists.txt
SUBST_FILES.xdg+=	libtaskmanager/CMakeLists.txt
SUBST_FILES.xdg+=	menu/desktop/CMakeLists.txt
SUBST_FILES.xdg+=	shell/CMakeLists.txt
SUBST_FILES.xdg+=	startkde/session-restore/CMakeLists.txt
SUBST_FILES.xdg+=	xembed-sni-proxy/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'
SUBST_SED.xdg+=		-e 's:{KDE_INSTALL_SYSCONFDIR}/xdg:{KDE_INSTALL_XDG_EX_DIR}:'
SUBST_SED.xdg+=		-e 's:{KDE_INSTALL_AUTOSTARTDIR}:{KDE_INSTALL_AUTOSTARTEXDIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/gmenudbusmenuproxy.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/gmenudbusmenuproxy.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/org.kde.plasma-fallback-session-restore.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.kde.plasma-fallback-session-restore.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/org.kde.plasmashell.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.kde.plasmashell.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/xembedsniproxy.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/xembedsniproxy.desktop
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/menus/plasma-applications.menu \
		${PKG_SYSCONFDIR}/xdg/menus/plasma-applications.menu
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/plasmanotifyrc \
		${PKG_SYSCONFDIR}/xdg/plasmanotifyrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/taskmanagerrulesrc \
		${PKG_SYSCONFDIR}/xdg/taskmanagerrulesrc

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-kcolorscheme/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/kf6-kdeclarative/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-kidletime/buildlink3.mk"
.include "../../devel/kf6-kitemmodels/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../devel/kf6-knotifyconfig/buildlink3.mk"
.include "../../devel/kf6-kpackage/buildlink3.mk"
.include "../../devel/kf6-kparts/buildlink3.mk"
.include "../../devel/kf6-krunner/buildlink3.mk"
.include "../../devel/kf6-ktexteditor/buildlink3.mk"
.include "../../devel/libudev-bsd/buildlink3.mk"
.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../devel/plasma6-kwayland/buildlink3.mk"
.include "../../devel/plasma6-plasma5support/buildlink3.mk"
.include "../../devel/qcoro/buildlink3.mk"
.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../geography/qt6-qtlocation/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../graphics/kf6-kiconthemes/buildlink3.mk"
.include "../../graphics/kf6-ksvg/buildlink3.mk"
.include "../../graphics/kf6-prison/buildlink3.mk"
.include "../../graphics/plasma6-breeze/buildlink3.mk"
.include "../../math/cln/buildlink3.mk"
.include "../../math/qalculate/buildlink3.mk"
.include "../../misc/kf6-kquickcharts/buildlink3.mk"
.include "../../misc/kf6-kstatusnotifieritem/buildlink3.mk"
.include "../../misc/kf6-kuserfeedback/buildlink3.mk"
.include "../../multimedia/phonon-qt6/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/kf6-baloo/buildlink3.mk"
.include "../../sysutils/kf6-kdbusaddons/buildlink3.mk"
.include "../../sysutils/plasma6-libksysguard/buildlink3.mk"
.include "../../security/kf6-kauth/buildlink3.mk"
.include "../../security/kf6-kwallet/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../time/kf6-kholidays/buildlink3.mk"
.include "../../time/plasma6-knighttime/buildlink3.mk"
.include "../../x11/kf6-kglobalaccel/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/kf6-kirigami/buildlink3.mk"
.include "../../x11/kf6-ktextwidgets/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/kirigami-addons/buildlink3.mk"
.include "../../x11/plasma6-plasma-activities/buildlink3.mk"
.include "../../x11/plasma6-plasma-activities-stats/buildlink3.mk"
.include "../../x11/plasma6-kscreenlocker/buildlink3.mk"
.include "../../x11/plasma6-layer-shell-qt/buildlink3.mk"
.include "../../x11/plasma6-libkscreen/buildlink3.mk"
.include "../../x11/plasma6-libplasma/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
