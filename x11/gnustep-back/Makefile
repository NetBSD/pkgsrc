# $NetBSD: Makefile,v 1.38 2006/12/15 20:33:04 joerg Exp $

DISTNAME=	gnustep-back-0.11.0
CATEGORIES=	x11 gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	X11 AppKit backend for GNUstep

USE_LANGUAGES=	objc
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--exec-prefix=${PREFIX}/libexec/GNUstep
MAKE_FILE=	GNUmakefile

pre-install:
	${INSTALL_DATA_DIR} ${GNUSTEP_SYSTEM_ROOT}/Library/Fonts

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glitz/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
