# $NetBSD: Makefile,v 1.14 2005/06/10 22:47:36 jlam Exp $

DISTNAME=	xcursorgen-4.3.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xsrc-manager@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	Create an X cursor file from a collection of PNG images

WRKSRC=		${WRKDIR}/${DISTNAME:C/-.*//}
USE_IMAKE=	YES

LIBPNG=		-L${BUILDLINK_PREFIX.png}/lib				\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.png}/lib	\
		-lpng

MAKE_FLAGS+=	LIBPNGLIB=${LIBPNG:Q}

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
