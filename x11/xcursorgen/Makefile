# $NetBSD: Makefile,v 1.1.1.1 2003/03/08 08:25:30 tron Exp $

DISTNAME=	xcursorgen-4.3.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xsrc-manager@netbsd.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	Create an X cursor file from a collection of PNG images

USE_BUILDLINK=	YES
USE_IMAKE=	YES

WRKSRC=		${WRKDIR}/${DISTNAME:C/-.*//}

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/bin/xcursor-config)
BROKEN=		This package requires XFree86 4.3.0 or newer.
.endif

.include "../../graphics/png/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
