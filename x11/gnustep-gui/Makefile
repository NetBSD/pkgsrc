# $NetBSD: Makefile,v 1.32 2006/07/22 05:10:55 rillig Exp $

DISTNAME=	gnustep-gui-0.10.3
PKGREVISION=	1
CATEGORIES=	x11 gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep AppKit Implementation

USE_LANGUAGES=	objc

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--exec-prefix=${PREFIX:Q}/libexec/GNUstep

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
