# $NetBSD: Makefile,v 1.1.1.1 2002/09/27 15:24:35 rh Exp $
#

DISTNAME=	gnustep-gui-0.8.1
CATEGORIES=	x11 gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep AppKit Implementation

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11=		YES
MAKEFILE=		GNUmakefile
GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/GNUstep
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
CPPFLAGS+=		-I${PREFIX}/share/GNUstep/System/Headers
CPPFLAGS+=		-I${PREFIX}/share/GNUstep/System/Headers/gnustep
LDFLAGS+=		-lossaudio

.include "../../devel/gnustep-base/buildlink2.mk"
.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
