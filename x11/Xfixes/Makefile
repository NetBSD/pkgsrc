# $NetBSD: Makefile,v 1.3 2004/02/14 17:21:55 jlam Exp $
#

DISTNAME=		libXfixes-2.0.0
PKGNAME=		${DISTNAME:S/libX/X/}
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		Xfixes extension of X RandR

USE_X11=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/xfixes.pc.in

.include "../../x11/fixesext/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
