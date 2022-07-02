# $NetBSD: Makefile,v 1.61 2022/07/02 16:53:40 ryoon Exp $

DISTNAME=	konsole-${KAPPSVER}
PKGREVISION=	9
CATEGORIES=	x11

HOMEPAGE=	http://kde.org/applications/system/konsole/
COMMENT=	Terminal emulator for the K Desktop Environment
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	kinit>=5.68.0:../../x11/kinit

USE_TOOLS+=	msgmerge

.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../devel/kpty/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
