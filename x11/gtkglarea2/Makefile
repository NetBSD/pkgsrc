# $NetBSD: Makefile,v 1.1.1.1 2003/05/09 14:40:17 drochner Exp $
#

DISTNAME=	gtkglarea-1.99.0
PKGNAME=	${DISTNAME:S/-/2-/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkglarea/1.99/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://www.gnome.org/
COMMENT=	OpenGL widget for the GTK+2 GUI toolkit

WRKSRC=		${WRKDIR}/gtkglarea-1.99.0
USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gtkgl-2.0.pc.in
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-lib-GL
CONFIGURE_ARGS+=	--with-GL-prefix=${BUILDLINK_PREFIX.MesaLib}

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
