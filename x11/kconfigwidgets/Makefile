# $NetBSD: Makefile,v 1.3 2016/07/09 06:39:17 wiz Exp $

DISTNAME=	kconfigwidgets-${KF5VER}
PKGREVISION=	1
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Widgets for KConfig
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

BUILD_DEPENDS+= kdoctools>=${KF5VER}:../../devel/kdoctools

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
.include "../../mk/bsd.pkg.mk"
