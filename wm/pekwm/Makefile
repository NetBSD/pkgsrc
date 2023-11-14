# $NetBSD: Makefile,v 1.66 2023/11/14 13:58:37 wiz Exp $

DISTNAME=	pekwm-0.3.0
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=pekdon/}
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://www.pekwm.se/
COMMENT=	Light, unobtrusive, and configurable window manager
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCMAKE_INSTALL_SYSCONFDIR=${PREFIX}/share/examples
CMAKE_ARGS+=	-DAWK=${AWK}
CMAKE_ARGS+=	-DSED=${SED}
CMAKE_ARGS+=	-DSH=${SH}
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
