# $NetBSD: Makefile,v 1.5 2004/02/15 09:47:48 recht Exp $
#

DISTNAME=		libXcursor-1.1.1
PKGNAME=		${DISTNAME:S/libX/x/}
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/Software/xlibs
COMMENT=		Client-side cursor loading library for X

USE_X11=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    xcursor.pc.in

BUILDLINK_DEPENDS.Xrender=	Xrender>=0.8

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/Xfixes/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
