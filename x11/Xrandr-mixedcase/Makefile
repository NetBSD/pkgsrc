# $NetBSD: Makefile,v 1.2 2004/02/14 17:21:55 jlam Exp $
#

DISTNAME=		libXrandr-1.0.1
PKGNAME=		Xrandr-1.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		X RandR extension (Library)

USE_X11=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/xrandr.pc.in

BUILDLINK_DEPENDS.Xrender=	Xrender>=0.8.2

.include "../../x11/randrext/buildlink2.mk"
.include "../../x11/Xrender/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
