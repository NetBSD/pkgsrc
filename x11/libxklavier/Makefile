# $NetBSD: Makefile,v 1.7 2004/10/02 15:44:15 jmmv Exp $
#

DISTNAME=	libxklavier-1.04
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gswitchit/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://pdx.freedesktop.org/Software/LibXklavier
COMMENT=	High-level API for the X Keyboard Extension (XKB)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_X11=		YES

PKGCONFIG_OVERRIDE=	libxklavier.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
