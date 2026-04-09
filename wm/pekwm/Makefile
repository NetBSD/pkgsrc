# $NetBSD: Makefile,v 1.78 2026/04/09 18:14:23 pin Exp $

DISTNAME=	pekwm-0.4.4
CATEGORIES=	wm
MASTER_SITES=	https://www.pekwm.se/pekwm/uv/

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://www.pekwm.se/
COMMENT=	Light, unobtrusive, and configurable window manager
LICENSE=	gnu-gpl-v2

# src/lib/Md5.cc:267:19: error: 'UINT32_MAX' was not declared in this scope; did you mean 'UINT_MAX'?
CFLAGS+=	-D__STDC_LIMIT_MACROS
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_SYSCONFDIR=${PREFIX}/share/examples
CMAKE_CONFIGURE_ARGS+=	-DAWK=${AWK}
CMAKE_CONFIGURE_ARGS+=	-DSED=${SED}
CMAKE_CONFIGURE_ARGS+=	-DSH=${SH}
CMAKE_ARG_PATH=		${WRKSRC}

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
