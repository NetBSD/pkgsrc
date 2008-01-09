# $NetBSD: Makefile,v 1.3 2008/01/09 04:16:41 bjs Exp $
#

DISTNAME=	pixman-0.9.6
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
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
