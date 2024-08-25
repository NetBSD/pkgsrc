# $NetBSD: Makefile,v 1.69 2024/08/25 06:19:18 wiz Exp $

DISTNAME=	pekwm-0.3.0
PKGREVISION=	3
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=pekdon/}
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://www.pekwm.se/
COMMENT=	Light, unobtrusive, and configurable window manager
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_SYSCONFDIR=${PREFIX}/share/examples
CMAKE_CONFIGURE_ARGS+=	-DAWK=${AWK}
CMAKE_CONFIGURE_ARGS+=	-DSED=${SED}
CMAKE_CONFIGURE_ARGS+=	-DSH=${SH}
CMAKE_ARG_PATH=	${WRKSRC}

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
