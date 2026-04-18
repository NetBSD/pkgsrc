# $NetBSD: Makefile,v 1.18 2026/04/18 09:23:28 kikadf Exp $

DISTNAME=	copyq-15.0.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=hluk/}
GH_PROJECT=	CopyQ
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://hluk.github.io/CopyQ
COMMENT=	Qt based clipboard manager
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
WRKSRC=			${WRKDIR}/${GH_PROJECT}-${PKGVERSION_NOREV}
CMAKE_CONFIGURE_ARGS+=	-DWITH_QT6=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_AUDIO=OFF
USE_TOOLS+=		pkg-config

.include "../../devel/cmake/build.mk"
.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kf6-kstatusnotifieritem/buildlink3.mk"
.include "../../security/qca2-qt6/buildlink3.mk"
.include "../../security/qt6-qtkeychain/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
