# $NetBSD: Makefile,v 1.20 2026/01/27 08:40:48 wiz Exp $

DISTNAME=	akregator-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	www

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Feed Reader by KDE
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-knotifyconfig/buildlink3.mk"
.include "../../devel/kf6-ktexteditor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kontactinterface/buildlink3.mk"
.include "../../misc/kf6-kstatusnotifieritem/buildlink3.mk"
.include "../../misc/kf6-kuserfeedback/buildlink3.mk"
.include "../../net/messagelib/buildlink3.mk"
.include "../../www/kf6-syndication/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
