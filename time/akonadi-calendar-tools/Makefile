# $NetBSD: Makefile,v 1.4 2023/11/12 13:23:43 wiz Exp $

DISTNAME=	akonadi-calendar-tools-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	time

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	CLI tools to manage akonadi calendars
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../time/calendarsupport/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
