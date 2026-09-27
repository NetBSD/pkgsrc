# $NetBSD: Makefile,v 1.38 2026/09/27 11:38:56 tnn Exp $

DISTNAME=	korganizer-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	time

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Calendar and scheduling Program
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/incidenceeditor/buildlink3.mk"
.include "../../misc/kdepim-runtime/buildlink3.mk"
.include "../../misc/kontactinterface/buildlink3.mk"
.include "../../misc/kf6-kuserfeedback/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
