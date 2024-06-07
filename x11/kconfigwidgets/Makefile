# $NetBSD: Makefile,v 1.73 2024/06/07 23:55:48 markd Exp $

DISTNAME=	kconfigwidgets-${KF5VER}
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Widgets for KConfig
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

TOOL_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools

USE_TOOLS+=	perl:run msgmerge

REPLACE_PERL+=	src/preparetips5

.include "../../lang/python/tool.mk"
.include "../../devel/kconfig/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../security/kauth/buildlink3.mk"
.include "../../textproc/kcodecs/buildlink3.mk"
.include "../../x11/kguiaddons/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
