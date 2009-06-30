# $NetBSD: Makefile,v 1.20 2009/06/30 00:07:25 joerg Exp $

DISTNAME=	xcursorgen-4.3.0
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xsrc-manager@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	Create an X cursor file from a collection of PNG images

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/${DISTNAME:C/-.*//}
USE_IMAKE=	YES

LIBPNG=		-L${BUILDLINK_PREFIX.png}/lib				\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.png}/lib	\
		-lpng

MAKE_FLAGS+=	LIBPNGLIB=${LIBPNG:Q}

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
