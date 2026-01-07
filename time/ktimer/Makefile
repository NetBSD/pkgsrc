# $NetBSD: Makefile,v 1.90 2026/01/07 08:49:12 wiz Exp $

DISTNAME=	ktimer-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	time

HOMEPAGE=	https://kde.org/applications/utilities/ktimer/
COMMENT=	KDE countdown launcher
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kf6-kstatusnotifieritem/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
