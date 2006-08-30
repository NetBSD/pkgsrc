# $NetBSD: Makefile,v 1.36 2006/08/30 14:55:41 adam Exp $

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

pre-install:
	${INSTALL_DATA_DIR} ${GNUSTEP_SYSTEM_ROOT}/Library/Fonts

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glitz/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
