# $NetBSD: Makefile,v 1.61 2022/01/30 20:26:57 nia Exp $

DISTNAME=	pekwm-0.2.1
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=pekdon/}
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://www.pekwm.se/
COMMENT=	Light, unobtrusive, and configurable window manager
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCMAKE_INSTALL_SYSCONFDIR=${PREFIX}/share/examples
CMAKE_ARGS+=	-DAWK=${AWK}
CMAKE_ARGS+=	-DSED=${SED}
CMAKE_ARGS+=	-DSH=${SH}
CMAKE_ARG_PATH=	${WRKSRC}

CONFIGURE_DIRS=	build
BUILD_DIRS=	build

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
