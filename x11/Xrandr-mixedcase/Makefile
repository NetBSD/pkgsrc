# $NetBSD: Makefile,v 1.4 2004/02/16 22:45:34 jlam Exp $
#

DISTNAME=		libXrandr-1.0.1
PKGNAME=		Xrandr-1.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		X RandR extension (Library)

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    xrandr.pc.in

BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.8

.include "../../x11/randrext/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
