# $NetBSD: Makefile,v 1.38 2008/04/25 05:21:30 wiz Exp $

DISTNAME=	fox-1.6.32
CATEGORIES=	x11
MASTER_SITES=	http://www.fox-toolkit.org/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fox-toolkit.org/
COMMENT=	Fast and extensive C++ GUI toolkit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-release
CONFIGURE_ARGS+=	--with-opengl
CONFIGURE_ARGS+=	--with-shm
CONFIGURE_ARGS+=	--with-xft
CONFIGURE_ARGS+=	--with-x

CONFIGURE_ENV+=		REAL_PTHREAD_LIBS=${PTHREAD_LIBS:Q}

.include "../../mk/bsd.prefs.mk"

# NetBSD < 3.0 does not have getpwnam_r() getpwuin_r()
.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[1-2]*) || ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	--disable-threadsafe
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
