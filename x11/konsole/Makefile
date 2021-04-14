# $NetBSD: Makefile,v 1.53 2021/04/14 22:39:25 markd Exp $

DISTNAME=	konsole-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	x11

HOMEPAGE=	http://kde.org/applications/system/konsole/
COMMENT=	Terminal emulator for the K Desktop Environment
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../devel/kpty/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
