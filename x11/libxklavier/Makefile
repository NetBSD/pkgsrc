# $NetBSD: Makefile,v 1.2 2004/04/01 18:12:58 jmmv Exp $
#

DISTNAME=	libxklavier-1.00
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gswitchit/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://pdx.freedesktop.org/Software/LibXklavier
COMMENT=	High-level API for the X Keyboard Extension (XKB)

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_X11=		YES

PKGCONFIG_OVERRIDE=	libxklavier.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
