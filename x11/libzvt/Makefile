# $NetBSD: Makefile,v 1.10 2004/02/14 17:21:56 jlam Exp $
#

DISTNAME=		libzvt-2.0.1
PKGREVISION=		5
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
PKGCONFIG_OVERRIDE=	${WRKSRC}/libzvt/libzvt-2.0.pc.in

.include "../../graphics/libart2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
