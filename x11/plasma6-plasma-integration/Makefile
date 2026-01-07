# $NetBSD: Makefile,v 1.2 2026/01/07 08:49:40 wiz Exp $

DISTNAME=	plasma-integration-${PLASMAVER}
PKGREVISION=	1
CATEGORIES=	x11

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	Integration of Qt application with KDE workspaces
LICENSE=	gnu-lgpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma6.mk"

DEPENDS+=	noto-ttf-[0-9]*:../../fonts/noto-ttf
DEPENDS+=	Hack-ttf-[0-9]*:../../fonts/Hack-ttf
DEPENDS+=	plasma6-xdg-desktop-portal-kde-[0-9]*:../../misc/plasma6-xdg-desktop-portal-kde
DEPENDS+=	kf6-qqc2-desktop-style-[0-9]*:../../x11/kf6-qqc2-desktop-style

USE_TOOLS+=	msgmerge pkg-config

REPLACE_PERL+=	src/platformtheme/*.pl

CMAKE_CONFIGURE_ARGS+=	-DBUILD_QT5=OFF

# Mute annoying messages. We install the following RUNTIME packages
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_FontNotoSans=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_FontNotoColorEmoji=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_FontHack=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_XDGDesktopPortalKDE=ON

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../devel/plasma6-kwayland/buildlink3.mk"
.include "../../graphics/kf6-kiconthemes/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../misc/kf6-kstatusnotifieritem/buildlink3.mk"
.include "../../x11/kf6-kconfigwidgets/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
