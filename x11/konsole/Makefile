# $NetBSD: Makefile,v 1.93 2026/02/06 10:06:15 wiz Exp $

DISTNAME=	konsole-${KAPPSVER}
PKGREVISION=	3
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
