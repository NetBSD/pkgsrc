# $NetBSD: Makefile,v 1.78 2024/02/06 11:17:43 markd Exp $

DISTNAME=	ktimer-${KAPPSVER}
CATEGORIES=	time

HOMEPAGE=	https://kde.org/applications/utilities/ktimer/
COMMENT=	KDE countdown launcher
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
