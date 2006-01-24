# $NetBSD: Makefile,v 1.13 2006/01/24 07:32:54 wiz Exp $
#

DISTNAME=	gtkglarea-1.99.0
PKGNAME=	${DISTNAME:S/-/2-/}
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkglarea/1.99/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	OpenGL widget for the GTK+2 GUI toolkit

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	gtkgl-2.0.pc.in
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-lib-GL
CONFIGURE_ARGS+=	--with-GL-prefix=${BUILDLINK_PREFIX.MesaLib}

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
