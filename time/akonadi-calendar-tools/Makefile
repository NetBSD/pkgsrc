# $NetBSD: Makefile,v 1.26 2026/09/06 11:03:08 markd Exp $

DISTNAME=	akonadi-calendar-tools-${KAPPSVER}
CATEGORIES=	time

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	CLI tools to manage akonadi calendars
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../time/calendarsupport/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
