# $NetBSD: Makefile,v 1.20 2004/11/16 06:13:15 rh Exp $

DISTNAME=		gnustep-back-0.9.4
PKGREVISION=		2
CATEGORIES=		x11 gnustep
MASTER_SITES=		${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnustep.org/
COMMENT=		X11 AppKit backend for GNUstep

USE_BUILDLINK3=		yes
USE_X11=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
