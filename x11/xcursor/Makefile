# $NetBSD: Makefile,v 1.1.1.1 2003/12/16 08:51:42 recht Exp $
#

DISTNAME=		libXcursor-1.1.1
PKGNAME=		${DISTNAME:S/libX/x/}
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/Software/xlibs
COMMENT=		Client-side cursor loading library for X

USE_X11=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/xcursor.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/Xfixes/buildlink2.mk"
.include "../../x11/Xrender/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
