# $NetBSD: Makefile,v 1.15 2004/04/10 23:46:55 rh Exp $
#

DISTNAME=	gnustep-back-0.9.2
CATEGORIES=	x11 gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	X11 AppKit backend for GNUstep

USE_BUILDLINK3=		yes
USE_X11=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep

.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
