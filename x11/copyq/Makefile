# $NetBSD: Makefile,v 1.8 2025/08/13 12:46:08 kikadf Exp $

DISTNAME=	copyq-10.0.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=hluk/}
GH_PROJECT=	CopyQ
GITHUB_TAG=	v${PKGVERSION_NOREV}

# Fix build with Qt 6.9, remove after release>10.0.0
PATCH_SITES=		${MASTER_SITES}${GH_PROJECT}/commit/
PATCH_DIST_STRIP=	-p1
PATCHFILES=		f08c0d46a239362c5d3525ef9c3ba943bb00f734.patch

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://hluk.github.io/CopyQ
COMMENT=	Qt based clipboard manager
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
WRKSRC=			${WRKDIR}/${GH_PROJECT}-${PKGVERSION_NOREV}
CMAKE_CONFIGURE_ARGS+=	-DWITH_QT6=ON
USE_TOOLS+=		pkg-config

.include "../../devel/cmake/build.mk"
.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kf6-kstatusnotifieritem/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
