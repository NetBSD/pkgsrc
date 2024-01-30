# $NetBSD: Makefile,v 1.5 2024/01/30 14:22:36 ryoon Exp $

DISTNAME=	akregator-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	www

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Feed Reader by KDE
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/ktexteditor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kontactinterface/buildlink3.mk"
.include "../../net/messagelib/buildlink3.mk"
.include "../../www/syndication/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
