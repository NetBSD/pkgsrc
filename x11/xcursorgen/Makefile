# $NetBSD: Makefile,v 1.8 2003/08/15 02:02:45 jmc Exp $

DISTNAME=	xcursorgen-4.3.0
WRKSRC=		${WRKDIR}/${DISTNAME:C/-.*//}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xsrc-manager@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	Create an X cursor file from a collection of PNG images

USE_BUILDLINK2=	YES
USE_IMAKE=	YES

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/bin/xcursor-config)
PKG_SKIP_REASON="This package requires XFree86 4.3.0 or newer."
.endif

.include "../../graphics/png/buildlink2.mk"

MAKE_ENV+=       LOCAL_LDFLAGS="-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.png_DEFAULT}/lib"

.include "../../mk/bsd.pkg.mk"
