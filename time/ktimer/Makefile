# $NetBSD: Makefile,v 1.61 2022/04/18 19:12:13 adam Exp $

DISTNAME=	ktimer-${KAPPSVER}
PKGREVISION=	6
CATEGORIES=	time

HOMEPAGE=	https://kde.org/applications/utilities/ktimer/
COMMENT=	KDE countdown launcher
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
