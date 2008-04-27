# $NetBSD: Makefile,v 1.10 2008/04/27 11:58:09 tnn Exp $
#

DISTNAME=	pixman-0.10.0
PKGNAME=	${DISTNAME:C/pl[0-9]*//}
PKGREVISION=	2
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

WRKSRC=	 	${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/bsd.pkg.mk"
