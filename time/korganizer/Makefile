# $NetBSD: Makefile,v 1.13 2023/11/12 13:23:44 wiz Exp $

DISTNAME=	korganizer-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	time

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Calendar and scheduling Program
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/incidenceeditor/buildlink3.mk"
.include "../../misc/kontactinterface/buildlink3.mk"
.include "../../misc/kdepim-runtime/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
