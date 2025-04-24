# $NetBSD: Makefile,v 1.7 2025/04/24 14:16:07 wiz Exp $

DISTNAME=	copyq-10.0.0
PKGREVISION=	1
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
