# $NetBSD: Makefile,v 1.23 2005/06/01 18:03:29 jlam Exp $

DISTNAME=	gnustep-gui-0.9.5
CATEGORIES=	x11 gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep AppKit Implementation

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
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
