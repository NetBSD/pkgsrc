# $NetBSD: Makefile,v 1.6 2004/02/14 17:21:56 jlam Exp $
#

DISTNAME=	gtkglarea-1.99.0
PKGNAME=	${DISTNAME:S/-/2-/}
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkglarea/1.99/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	OpenGL widget for the GTK+2 GUI toolkit

WRKSRC=		${WRKDIR}/gtkglarea-1.99.0
USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gtkgl-2.0.pc.in
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-lib-GL
CONFIGURE_ARGS+=	--with-GL-prefix=${BUILDLINK_PREFIX.MesaLib}

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
