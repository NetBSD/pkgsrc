# $NetBSD: Makefile,v 1.13 2005/03/14 22:54:51 jmmv Exp $
#

DISTNAME=		libzvt-2.0.1
PKGREVISION=		6
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libzvt/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Virtual Terminal Widget Library for GNOME2

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_X11=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	libzvt/libzvt-2.0.pc.in

.include "../../graphics/libart2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
