# $NetBSD: Makefile,v 1.1.1.1 2007/11/08 19:51:43 bjs Exp $
#

DISTNAME=	pixman-0.9.6
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Library of low-level pixel manipulation routines

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	pixman-1.pc.in

.include "../../mk/bsd.pkg.mk"
