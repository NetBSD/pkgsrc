# $NetBSD: Makefile,v 1.17 2020/04/12 08:29:17 adam Exp $

DISTNAME=	kimagemapeditor-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	www

HOMEPAGE=	https://www.kde.org/
COMMENT=	HTML Image Map Editor
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.1

# newer versions require qt5-qtwebengine
KAPPSVER=	19.08.3
MASTER_SITES=	${MASTER_SITE_KDE:=applications/${KAPPSVER}/src/}
.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kparts/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/khtml/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
