# $NetBSD: Makefile,v 1.6 2026/10/31 17:38:08 kikadf Exp $

DISTNAME=	labwc-tweaks-0.2.0
CATEGORIES=	wayland
MASTER_SITES=	${MASTER_SITE_GITHUB:=labwc/}

MAINTAINER=	kikadf@NetBSD.org
HOMEPAGE=	https://labwc.github.io/
COMMENT=	Qt configuration tool for labwc
LICENSE=	gnu-gpl-v2 AND modified-bsd

USE_LANGUAGES=		c++
USE_CXX_FEATURES=	c++23
USE_TOOLS+=		pkg-config perl

.include "../../devel/cmake/build.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt6-qttols=	build
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
