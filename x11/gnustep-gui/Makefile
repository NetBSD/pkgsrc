# $NetBSD: Makefile,v 1.18 2004/09/27 01:07:23 rh Exp $

DISTNAME=	gnustep-gui-0.9.4
CATEGORIES=	x11 gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep AppKit Implementation

USE_BUILDLINK3=		yes
USE_X11=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"

.if !empty(HAVE_OSS:M[Nn][Oo]) && !exists(/usr/include/soundcard.h) && \
    !exists(/usr/include/sys/soundcard.h) &&				\
    !exists(/usr/include/machine/soundcard.h)
CONFIGURE_ARGS+=--disable-gsnd
PLIST_SUBST+=	GSND="@comment "
.else
PLIST_SUBST+=	GSND=
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
