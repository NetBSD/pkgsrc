# $NetBSD: Makefile,v 1.1.1.1 2002/12/18 20:09:16 jmmv Exp $
#

DISTNAME=	waimea-0.4.0
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=waimea/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.waimea.org/
COMMENT=	Fast and highly customizable virtual window manager

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11=	YES

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/extensions/Xinerama.h)
CONFIGURE_ARGS+=	--disable-xinerama
.endif

.if !exists(${X11BASE}/include/X11/extensions/Xrender.h)
CONFIGURE_ARGS+=	--disable-render
.endif

.if !exists(${X11BASE}/include/X11/extensions/shape.h)
CONFIGURE_ARGS+=	--disable-shape
.endif

CONFIGURE_ARGS+=	--disable-randr

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/imlib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
