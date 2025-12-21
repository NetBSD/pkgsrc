# $NetBSD: Makefile,v 1.90 2025/12/21 20:19:56 markd Exp $

DISTNAME=	konsole-${KAPPSVER}
CATEGORIES=	x11

HOMEPAGE=	https://apps.kde.org/konsole/
COMMENT=	Terminal emulator for the K Desktop Environment
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-knotifyconfig/buildlink3.mk"
.include "../../devel/kf6-kparts/buildlink3.mk"
.include "../../devel/kf6-kpty/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
