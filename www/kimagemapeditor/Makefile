# $NetBSD: Makefile,v 1.63 2026/05/14 16:42:20 ryoon Exp $

DISTNAME=	kimagemapeditor-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	www

HOMEPAGE=	https://www.kde.org/
COMMENT=	HTML Image Map Editor
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.1

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kf6-kparts/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/qt6-qtwebengine/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
