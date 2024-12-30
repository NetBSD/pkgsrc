# $NetBSD: Makefile,v 1.72 2024/12/30 21:50:52 pin Exp $

DISTNAME=	release-0.3.2
GITHUB_PROJECT=	pekwm
GITHUB_TAG=	refs/tags/release-0.3.2
PKGNAME=	${GITHUB_PROJECT}-0.3.2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=pekdon/}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://www.pekwm.se/
COMMENT=	Light, unobtrusive, and configurable window manager
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/pekwm-release-0.3.2

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
