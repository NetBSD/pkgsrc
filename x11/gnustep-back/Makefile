# $NetBSD: Makefile,v 1.56 2013/06/04 22:17:19 tron Exp $

DISTNAME=	gnustep-back-0.22.0
PKGREVISION=	4
CATEGORIES=	x11 gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	X11 AppKit backend for GNUstep
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		objc
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
LDFLAGS=		${LINKER_RPATH_FLAG}${PREFIX}/lib
MAKE_FILE=		GNUmakefile

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${GNUSTEP_ROOT}/lib/GNUstep/Fonts

.include "../../devel/gnustep-make/gnustep.mk"

PREFER_PKGSRC+=	freetype2

.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
